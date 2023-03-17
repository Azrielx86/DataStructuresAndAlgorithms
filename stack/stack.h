#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <memory>

/**
 *@brief Class that defines an stack structure
 *
 * @tparam T
 */
template <class T>
class Stack
{
private:
  std::unique_ptr<T[]> _data;
  int _top;
  int _max_size;
public:
  Stack(int max_size);
  /**
   *@brief Push an value to the stack.
   * @tparam T An value of the type defined in the stack
   * @param value New value
   */
  void push(T value);

  /**
   *@brief Pops the last value in the stack
   *
   * @return T* Last value in the stack
   */
  T* pop();
};

#include "stack.cpp"

#endif
