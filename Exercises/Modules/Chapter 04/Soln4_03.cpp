// Exercise 4-3 Using nested ifs and a logical && to check the value of a number.

import std;

int main()
{
  double value {};

  std::print("Please enter a number between 1 and 100: ");
  std::cin >> value;
  std::println("");

  std::print("The number you entered, {}, is ", value);

  if (value >= 1 && value <= 100)
  {
    if (value > 50)
      std::print("greater than");
    else if (value < 50)
      std::print("less than");
    else
      std::print("equal to");
  
    std::println(" 50.");
  }
  else
  {
    std::println("not between 1 and 100.");
  }
}