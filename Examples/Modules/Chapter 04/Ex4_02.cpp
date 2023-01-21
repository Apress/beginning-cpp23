// Three-way comparison of integers
import std; // Required also for using operator <=> (even for fundamental types)

int main()
{
  std::print("Please enter a number: ");
  int value;
  std::cin >> value;

  std::strong_ordering ordering{ value <=> 0 };

  std::println("value < 0: {}", ordering == std::strong_ordering::less);
  std::println("value > 0: {}", ordering == std::strong_ordering::greater);
  std::println("value == 0: {}", ordering == std::strong_ordering::equal);
}
