#include "stack.h"

template<class T>
Stack<T>::Stack(int max_size)
{
  this->_max_size = max_size;
  this->_data = std::make_unique<T[]>(this->_max_size * sizeof(T));
  this->_top = -1;
}

template <class T>
void Stack<T>::push(T value)
{
  if (this->_top >= this->_max_size - 1)
    std::cerr << "Stack overflow\n";
  else
    this->_data[++this->_top] = value;
}

template <class T>
T* Stack<T>::pop()
{
  if (this->_top < 0)
  {
    std::cerr << "Empty stack\n";
    return nullptr;
  }
  else
  {
    return &this->_data[this->_top--];
  }
}