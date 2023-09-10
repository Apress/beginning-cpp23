// Generic lambdas
import std;
import optimum;

int main()
{
  std::vector numbers{ 91, 18, 92, 22, 13, 43 };
  std::println("Minimum element: {}", *findOptimum(numbers, std::less<>{}));
  std::println("Maximum element: {}", *findOptimum(numbers, std::greater<>{}));

  // Define two generic comparison functions:
  auto alpha{ [](const auto& x, const auto& y) { return x > y; } };
  auto longer{ [](const auto& x, const auto& y) { return x.length() > y.length(); } };

  // Both of course work for strings:
  std::vector<std::string> names{ "Moe", "Larry", "Shemp", "Curly", "Joe", "Curly Joe" };
  std::println("Alphabetically last name: {}", *findOptimum(names, alpha));
  std::println("Longest name: {}", *findOptimum(names, longer));

  // The generic alpha functor works for any types that allow > comparison:
  std::println("{} {} {}", alpha(1, 2), alpha(3.0, 4.0), alpha(5, 6.0));
}
