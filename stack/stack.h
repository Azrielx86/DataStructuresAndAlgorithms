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
	T *pop( );
};

template <class T>
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
T *Stack<T>::pop( )
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

#endif
