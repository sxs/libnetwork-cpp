#ifndef SC_EPOLL_UTILS_H_
#define SC_EPOLL_UTILS_H_

#include <sys/epoll.h>
#include <cassert>
#include <unistd.h>

namespace net {

class EpollUtils {
 public:
  
   /**
    * @brief constructor
    *
    * @param is_et 默认ET模式
    */
  explicit EpollUtils(bool is_et = true)
      : my_epoll_fd_(-1),
        my_events_(NULL),
        my_is_et_(is_et),
        my_max_connections_(1024)
  { }
        
  
  /**
   * @brief destructor
   */
  ~EpollUtils() {
    if (my_events_ != NULL) {
      delete[] my_events_;
      my_events_ = NULL;
    }

    if (my_epoll_fd_ > 0)
      close(my_epoll_fd_);
  }

  void Create(uint32_t max_connections);

  void Add(int fd, long long data, uint32_t event);
  
  void Mod(int fd, long long data, uint32_t event);

  void Del(int fd, long long data, uint32_t event);

  int Wait(int ms_time);

  struct epoll_event& Get(uint32_t i);

  //noncopyable
  EpollUtils(const EpollUtils&) = delete;
  EpollUtils& operator=(const EpollUtils&) = delete;
 private:
  void Ctrl(int fd, int op, long long data, uint32_t events);

 private:
  
  int my_epoll_fd_;

  struct epoll_event* my_events_;

  bool my_is_et_;

  uint32_t my_max_connections_;

};

}
#endif
