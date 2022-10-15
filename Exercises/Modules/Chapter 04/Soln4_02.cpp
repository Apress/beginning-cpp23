// Exercise 4-2 Testing for exact division of one integer by another.
//              We can use an if statement to check that the input is valid 
//              and we can use another to arrange the input as we need. 
//              Then we use an if-else to generate the appropriate output.

import std;

int main()
{
  int value1 {};
  int value2 {};

  std::print("Please input two positive integers, separated by a space: ");
  std::cin >> value1 >> value2;
  std::println("");

  if (value1 <= 0 || value2 <= 0)  // Valid input?
  {
    std::println("Sorry - positive integers only.");
    return 1;
  }

  // Ensure that value1 is not smaller than value2
  if (value1 < value2)
  {         
    const auto temp{ value1 };    // swap if necessary
    value1 = value2;
    value2 = temp;
  }

  // Notice the use of argument indices to reorder value1 and value2 (see Chapter 2)
  if (value1 % value2 == 0)
    std::println("{1} divides into {0} exactly. ", value1, value2);
  else 
    std::println("{0} is not exactly divisible by {1}.", value1, value2);
}