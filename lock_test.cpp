#include "lock.h"
#include <iostream>

static int kCount = 1;
net::ThreadMutex kMutex;

using namespace std;

void* TestLock1(void*) {
  net::ThreadLock lock(kMutex);
  while (kCount <= 10) {
    cout << kCount++ << endl;
  }
  return NULL;
  //net::LockT<net::ThreadMutex> lock(mutex);
}

void* TestLock2(void*) {
  net::ThreadLock lock(kMutex);
  while (kCount <= 20) {
    cout << kCount++ << endl;
  }
  //net::LockT<net::ThreadMutex> lock(mutex);
  return NULL;
}

int main() {
  pthread_t pid1, pid2;
  pthread_create(&pid1, NULL, TestLock1, NULL);
  pthread_create(&pid2, NULL, TestLock2, NULL);
  pthread_join(pid1, NULL);
  pthread_join(pid2, NULL);
  return 0;
}
