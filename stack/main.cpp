#include <iostream>
#include "stack.h"

int main(int argc, char const* argv[])
{
  int stack_size = 15;
  Stack<int> my_stack(stack_size);

  std::cout << "Pushing values: ";
  for (int i = 0; i < stack_size; i++)
  {
    std::cout << i << " ";
    my_stack.push(i);
  }
  std::cout << std::endl;

  std::cout << "Popping values: ";
  for (int i = 0; i < stack_size; i++)
  {
    auto value = my_stack.pop();
    if (value != nullptr)
      std::cout << *value << " ";
  }
  std::cout << std::endl;

  return 0;
}
