#ifndef SC_CONDITION_H_
#define SC_CONDITION_H_

namespace net {

class ThreadMutex;

class Condition {
 public:
  Condition();
  ~Condition();

  //noncopyable
  Condition(const Condition&) = delete;
  const Condition& operator=(const Condition&) = delete;

  void Signal();

};
}

#endif
