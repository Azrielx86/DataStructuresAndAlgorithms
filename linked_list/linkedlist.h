#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "node.h"
#include <iostream>
#include <memory>

template <class T>
class LinkedList
{
  private:
	std::shared_ptr<Node<T>> _head;
	int _size;

  public:
	LinkedList<T>();
	void insert(T value);
	void insert(T value, int index);
	void remove(int index);
	void size();
	friend std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list)
	{
		if (list._head == nullptr)
			return os;

		Node<T> *position = list._head.get();

		os << "[ ";
		while (position->get_next() != nullptr)
		{
			os << position->get_value() << ", ";
			position = position->get_next().get();
		}

		os << position->get_value() << " ]";

		return os;
	}
};

template <class T>
LinkedList<T>::LinkedList()
{
	_head = nullptr;
}

template <class T>
void LinkedList<T>::insert(T value)
{
	if (_head == nullptr)
	{
		_head = std::make_shared<Node<T>>(Node<T>(value));
		return;
	}

	Node<T> *position = _head.get();
	while (position->get_next() != nullptr)
		position = position->get_next().get();

	position->set_next(std::make_shared<Node<T>>(Node<T>(value)));
}

#endif