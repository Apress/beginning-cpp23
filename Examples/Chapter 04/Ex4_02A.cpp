// Using the named comparison functions
import std;

int main()
{
  std::print("Please enter a number: ");

  int value;
  std::cin >> value;

  std::strong_ordering ordering{ value <=> 0 };

  std::println("value < 0: {}", std::is_lt(ordering));  // is less than
  std::println("value > 0: {}", std::is_gt(ordering));  // is greater than
  std::println("value == 0: {}", std::is_eq(ordering)); // is equivalent
}
