#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <memory>

template <class T>
class Node
{
  private:
	T _value;
	std::shared_ptr<Node<T>> _next;

  public:
	Node<T>(T value);
	T get_value();
	void set_value(T value);
	std::shared_ptr<Node<T>> get_next();
	void set_next(std::shared_ptr<Node<T>> node);
};

template <class T>
Node<T>::Node(T value)
{
	_value = value;
	_next = nullptr;
}

template <class T>
inline T Node<T>::get_value()
{
	return _value;
}

template <class T>
inline void Node<T>::set_value(T value)
{
	_value = value;
}

template <class T>
inline std::shared_ptr<Node<T>> Node<T>::get_next()
{
	return _next;
}

template <class T>
inline void Node<T>::set_next(std::shared_ptr<Node<T>> node)
{
	if (_next == nullptr)
		_next.reset();

	_next = node;
}

#endif