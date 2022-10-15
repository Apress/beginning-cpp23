// Exercise 4-1 Testing whether two integer values are equal. 

import std;

int main()
{
  int value1 {};
  int value2 {};

  std::print("Please input two integers, separated by a space: ");
  std::cin >> value1 >> value2;
  std::println("");

  if (value1 == value2)
    std::println("The values you entered are the same (two times {}).", value1);
  else 
    std::println("The values you entered are not the same ({} != {}).", value1, value2);
}