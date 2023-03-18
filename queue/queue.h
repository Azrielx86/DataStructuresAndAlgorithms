#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <memory>

template <class T>
class Queue
{
private:
  std::unique_ptr<T[]> _data;
  int _max_size;
  int _last;
public:
  Queue(int max_size);
  void push();
  T* pop();
};

#include "queue.cpp"

#endif