#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "node.h"
#include <iostream>
#include <memory>
#include <stdexcept>

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
	int size();
	friend std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list)
	{
		if (list._head == nullptr) return os;

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
	_size = 0;
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
	_size++;
}

template <class T>
void LinkedList<T>::insert(T value, int index)
{
	if (index >= _size) throw std::out_of_range("Index out of range!");

	std::shared_ptr<Node<T>> new_node =
	    std::make_shared<Node<T>>(Node<T>(value));

	if (_head == nullptr) { _head = new_node; }
	else if (index == 0)
	{
		new_node.get()->set_next(_head);
		_head = new_node;
	}
	else if (index == _size) { this->insert(value); }
	else
	{

		int pos = 0;
		Node<T> *pos_node = _head.get();
		while (pos_node->get_next() != nullptr && index > ++pos)
		{
			pos_node = pos_node->get_next().get();
		}

		new_node->set_next(pos_node->get_next());
		pos_node->set_next(new_node);
	}

	_size++;
}

template <class T>
void LinkedList<T>::remove(int index)
{
	if (index > _size) std::out_of_range("Index out of range!");
	if (index == 0)
	{
		std::shared_ptr<Node<T>> old_node = _head;
		_head = old_node.get()->get_next();
		old_node.get()->set_next(nullptr);
	}
	else if (index == _size)
	{
		Node<T> *position = _head.get();
		while (position->get_next()->get_next() != nullptr)
			position = position->get_next().get();
		position->set_next(nullptr);
	}
	else
	{
		int pos = 0;
		Node<T> *pos_node = _head.get();
		while (pos_node->get_next() != nullptr && index > ++pos)
			pos_node = pos_node->get_next().get();

		std::shared_ptr<Node<T>> old_node = pos_node->get_next();
		pos_node->set_next(old_node.get()->get_next());
	}

	_size--;
}

template <class T>
inline int LinkedList<T>::size()
{
	return _size;
}

#endif