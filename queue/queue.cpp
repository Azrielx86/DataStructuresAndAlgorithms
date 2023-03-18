#include "queue.h"

template<class T>
Queue<T>::Queue(int max_size)
{
  this->_max_size = max_size;
  this->_data = std::make_unique<T[]>(this->_max_size * sizeof(T));
  if (this->_data == nullptr)
    throw std::exception();
}

template<class T>
void Queue<T>::push() {}

template<class T>
T* Queue<T>::pop() {}