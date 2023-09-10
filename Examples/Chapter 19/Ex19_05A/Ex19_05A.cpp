// If possible, using the standard functors instead of lambda expressions 
// often leads to more compact and elegant code.
import std;
import optimum;

int main()
{
  std::vector numbers{ 91, 18, 92, 22, 13, 43 };
  std::println("Minimum element: {}", *findOptimum(numbers, std::less<>{}));
  std::println("Maximum element: {}", *findOptimum(numbers, std::greater<>{}));

  // Define two anonymous comparison functions for strings:
  auto alpha{ std::greater<>{} };
  auto longer{ [](std::string_view x, std::string_view y) { return x.length() > y.length(); } };

  std::vector<std::string> names{ "Moe", "Larry", "Shemp", "Curly", "Joe", "Curly Joe" };
  std::println("Alphabetically last name: {}", *findOptimum(names, alpha));
  std::println("Longest name: {}", *findOptimum(names, longer));
}
