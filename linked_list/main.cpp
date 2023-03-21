#include "linkedlist.h"
#include <iostream>
#include <ostream>


int main()
{
	LinkedList<int> my_list;
	my_list.insert(15);
	my_list.insert(16);
	my_list.insert(17);
	std::cout << my_list << std::endl;
}