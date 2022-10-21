// Your first algorithms: std::min_element() and max_element(),
// this time using the range-based versions.
import std;

int main()
{
  std::vector numbers{ 91, 18, 92, 22, 13, 43 };
  std::println("Minimum element: {}", *std::ranges::min_element(numbers));
  std::println("Maximum element: {}", *std::ranges::max_element(numbers));

  int number_to_search_for {};
  std::print("Please enter a number: ");
  std::cin >> number_to_search_for;

  auto nearer { [=](int x, int y) {
    return std::abs(x - number_to_search_for) < std::abs(y - number_to_search_for);
  }};

  std::println("The number nearest to {} is {}", 
     number_to_search_for, *std::ranges::min_element(numbers, nearer));
  std::println("The number furthest from {} is {}",
     number_to_search_for, *std::ranges::max_element(numbers, nearer));

/*
  const auto [nearest, furthest] { std::ranges::minmax_element(numbers, nearer) };

  std::println("The number nearest to {} is {}", number_to_search_for, *nearest);
  std::println("The number furthest from {} is {}", number_to_search_for,
                                                                      *furthest);
*/
}