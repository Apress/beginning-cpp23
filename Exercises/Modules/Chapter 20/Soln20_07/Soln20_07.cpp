// Removing all elements that satisfy a certain condition 
// while iterating over a container
import std;

using namespace std::ranges::views;

int main()
{
  const int num_numbers{ 15 };

  auto numbers{ iota(1, num_numbers + 1) };

  std::println("The original set of numbers: {:n}", numbers);

  auto odd_numbers{ numbers | filter([](int i) { return i % 2 != 0; }) };

  std::println("The numbers that were kept: {:n}", odd_numbers);
}