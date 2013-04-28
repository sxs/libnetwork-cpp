#ifndef SC_THREAD_MUTEX_H_
#define SC_THREAD_MUTEX_H_

#include <pthread.h>

namespace net {
class ThreadMutex {
 public:
  ThreadMutex() { pthread_mutex_init(&my_mutex_, NULL); }
  ~ThreadMutex() { pthread_mutex_destroy(&my_mutex_); }

  //noncopyable
  ThreadMutex(const ThreadMutex&) = delete;
  ThreadMutex& operator=(const ThreadMutex&) = delete;

  void Lock() { pthread_mutex_lock(&my_mutex_); }

  void UnLock() { pthread_mutex_unlock(&my_mutex_); }

  pthread_mutex_t* GetPthreadMutex() { return &my_mutex_; } 

 private:
  pthread_mutex_t my_mutex_;
};
}

#endif
