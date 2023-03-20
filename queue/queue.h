#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <memory>
#include <stdexcept>

/**
 * @brief Represents a Queue
 *
 * @tparam T Queue data type
 */
template <class T>
class Queue
{
  private:
	std::unique_ptr<T[]> _data;
	int _max_size;
	int _last;
	int _first;

  public:
	Queue(int max_size);
	/**
	 * @brief Adds a value in the queue
	 *
	 * @param data
	 */
	void enqueue(T data);

	/**
	 * @brief Removes the data from the first position
	 *
	 * @return T value removed
	 */
	T dequeue();

	/**
	 * @brief Returns the first value in the queue
	 * without removing it.
	 *
	 * @return T Value from the first position
	 */
	T first();

	/**
	 * @brief Returns the last position in the queue
	 * without removing it.
	 *
	 * @return T Value from the last position.
	 */
	T last();

	/**
	 * @brief Checks if queue is full
	 */
	bool is_full();

	/**
	 * @brief Checks if queue is empty.
	 */
	bool is_empty();

	/**
	 * @return int Current size of the queue
	 */
	int current_size();

	friend std::ostream &operator<<(std::ostream &os, const Queue<T> &q)
	{
		for (int i = q._first; i < q._last; i++)
			os << q._data[i] << " ";
		return os;
	}
};

template <class T>
Queue<T>::Queue(int max_size)
{
	_max_size = max_size;
	_data = std::make_unique<T[]>(_max_size * sizeof(T));

	_first = -1;
	_last = -1;
}

template <class T>
void Queue<T>::enqueue(T data)
{
	if (is_full())
		return;

	_data[++_last] = data;

	if (_last == 0)
		_first = 0;
}

template <class T>
T Queue<T>::dequeue()
{
	if (is_empty())
		throw std::out_of_range("Queue is empty!");

	T data = _data[_first];

	if (_first == _last)
		_last = _first = -1;
	else
		_first++;

	return data;
}

template <class T>
T Queue<T>::first()
{
	if (is_empty())
		throw std::out_of_range("Queue is empty!");
	return _data[_first];
}

template <class T>
T Queue<T>::last()
{
	if (is_empty())
		throw std::out_of_range("Queue is empty!");
	return _data[_last];
}

template <class T>
inline bool Queue<T>::is_empty()
{
	return (_first == -1);
}

template <class T>
inline bool Queue<T>::is_full()
{
	return (_last == _max_size - 1);
}

template <class T>
inline int Queue<T>::current_size()
{
	return _last - _first + 1;
}

#endif