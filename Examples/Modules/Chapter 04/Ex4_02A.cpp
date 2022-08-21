// Using the named comparison functions
import <compare>;  // Required when using operator <=> (even for fundamental types)
#include <print>

int main()
{
  std::cout << "Please enter a number: ";

  int value;
  std::cin >> value;

  std::strong_ordering ordering{ value <=> 0 };

  std::println("value < 0: {}", std::is_lt(ordering));  // is less than
  std::println("value > 0: {}", std::is_gt(ordering));  // is greater than
  std::println("value == 0: {}", std::is_eq(ordering)); // is equivalent
}
