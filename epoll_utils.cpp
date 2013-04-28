#include "epoll_utils.h"

namespace net {

//void Ctrl(int fd, int op, long long data, uint32_t events);
void EpollUtils::Ctrl(int fd, 
                      int op,
                      long long data, 
                      uint32_t events) {
  struct epoll_event ev;
  ev.data.u64 = data;
  if (my_is_et_)
    ev.events = events | EPOLLET;
  else
    ev.events = events;

  epoll_ctl(my_epoll_fd_, op, fd, &ev);
}

void EpollUtils::Create(uint32_t max_connections) {
  my_max_connections_ = max_connections;
  my_epoll_fd_ = epoll_create(my_max_connections_ + 1);
  if (my_events_ != NULL)
    delete[] my_events_;

  my_events_ = new epoll_event[my_max_connections_ + 1];
}

void EpollUtils::Add(int fd, long long data, uint32_t event) {
  Ctrl(fd, EPOLL_CTL_ADD, data, event);
}
  
void EpollUtils::Mod(int fd, long long data, uint32_t event) {
  Ctrl(fd, EPOLL_CTL_ADD, data, event);
}

void EpollUtils::Del(int fd, long long data, uint32_t event) {
  Ctrl(fd, EPOLL_CTL_DEL, data, event);
}

int EpollUtils::Wait(int ms_time) {
  return epoll_wait(my_epoll_fd_, 
                    my_events_, 
                    my_max_connections_ + 1, 
                    ms_time);
}

struct epoll_event& EpollUtils::Get(uint32_t i) {
  assert(my_events_ != NULL);
  return my_events_[i];
}

}
