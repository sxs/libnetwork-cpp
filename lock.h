#ifndef SC_LOCK_H_
#define SC_LOCK_H_

#include "thread_mutex.h"

namespace net {

template <class T>
class LockT {
 public:
  explicit LockT(T& mutex) : my_mutex_(mutex)
  { my_mutex_.Lock(); }

  ~LockT() { my_mutex_.UnLock(); }

  //noncopyable
  LockT(const LockT&) = delete;
  LockT& operator=(const LockT&) = delete;

 private:
  T& my_mutex_;
};

typedef LockT<ThreadMutex> ThreadLock;

}

#endif
