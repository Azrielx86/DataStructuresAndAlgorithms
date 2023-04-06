#include "linkedlist.h"
#include <iostream>
#include <ostream>

int main()
{
	LinkedList<int> my_list;

	for (int i = 15; i <= 25; i++)
		my_list.insert(i);

	my_list.remove(0);              // 15 in list, remove head
	my_list.remove(my_list.size()); // 25 in list, remove end
	my_list.remove(3);              // 19 in list, remove index

	my_list.insert(15, 0); // insert to head
	my_list.insert(25);    // insert to end
	my_list.insert(19, 4); // insert to index

	std::cout << my_list << "\n";
	std::cout << "Size: " << my_list.size() << "\n";
}