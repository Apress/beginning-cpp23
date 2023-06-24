// Your first algorithms: std::min_element() and max_element()
import std;

int main()
{
  std::vector numbers{ 91, 18, 92, 22, 13, 43 };
  std::println("Minimum element: {}", *std::min_element(begin(numbers), end(numbers)));
  std::println("Maximum element: {}", *std::max_element(begin(numbers), end(numbers)));

  int number_to_search_for {};
  std::print("Please enter a number: ");
  std::cin >> number_to_search_for;

  auto nearer { [=](int x, int y) {
    return std::abs(x - number_to_search_for) < std::abs(y - number_to_search_for);
  }};

  std::println("The number nearest to {} is {}", 
     number_to_search_for, *std::min_element(begin(numbers), end(numbers), nearer));
  std::println("The number furthest from {} is {}",
     number_to_search_for, *std::max_element(begin(numbers), end(numbers), nearer));

/*
  const auto [nearest, furthest]
    { std::minmax_element(begin(numbers), end(numbers), nearer) };

  std::println("The number nearest to {} is {}", number_to_search_for, *nearest);
  std::println("The number furthest from {} is {}", number_to_search_for,
                                                                      *furthest);
*/
}
