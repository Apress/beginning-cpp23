// Sorting in various ways using higher-order functions, functors, and lambda expressions.

import std;
import sort;

int main()
{
  std::vector numbers{ -2, 4, -5, 6, 10, -40, 56, 4, 67, 45 };
  std::println("Integers to be sorted: {:n:2}", numbers);
  sort(numbers, std::greater<>{});
  std::println("Sorted integers:       {:n:2}", numbers);

  std::vector letters{ 'C', 'd', 'a', 'z', 't', 'S', 'p', 'm', 'D', 'f' };
  std::println("\nCharacters to be sorted: {:n}", letters);
  sort(letters, [](char x, char y) { return std::tolower(x) < std::tolower(y); });
  std::println("Sorted characters:       {:n}", letters);

  std::vector values{ -2.5, 1.4, -2.55, 6.3, 10.1, -40.5, 56.0, 4.7, 67.3, 45.0 };
  std::println("\nFloating-point values to be sorted: {:n:4}", values);
  sort(values, [](double x, double y) { return std::abs(x) < std::abs(y); });
  std::println("Sorted floating-point values:       {:n:4}", values);
}