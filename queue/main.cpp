#include "queue.h"
#include <iostream>

int main(int argc, char const *argv[])
{
	int size = 15;
	Queue<int> my_queue(15);

	std::cout << "Enqueue data\n";
	for (int i = 0; i < size; i++)
		my_queue.enqueue(i);

	std::cout << "Current queue state: " << my_queue << std::endl;

	std::cout << "Current size: " << my_queue.current_size() << std::endl;
	std::cout << "First element in queue: " << my_queue.first() << std::endl;
	std::cout << "Last element in queue: " << my_queue.last() << std::endl;

	std::cout << "Dequeue data\n";
	for (int i = 0; i < size; i++)
	{
		auto data = my_queue.dequeue();
		std::cout << data << " ";
	}
	std::cout << std::endl;

	return 0;
}
