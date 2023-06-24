// Removing all elements that satisfy a certain condition 
// while iterating over a container
import std;

/*
  Note: std::ranges::iota() does not exist. No doubt because 
  the <ranges> module defines a std::ranges::views::iota range factory.
  Maybe you can alter this solution to use that view instead to fill the vector?
  (Note: in the next exercise you are asked to not use a vector at all,
   but operate directly with views...)
*/

std::vector<int> fillVector_1toN(int N);  // Fill a vector with 1, 2, ..., N

void removeEvenNumbers(auto& numbers)    /* Using more elegant std::erase_if() */
{
  std::erase_if(numbers, [](auto number) { return number % 2 == 0; });
}

int main()
{
  const int num_numbers{15};

  auto numbers{ fillVector_1toN(num_numbers) };

  std::println("The original set of numbers: {:n}", numbers);

  removeEvenNumbers(numbers);

  std::println("The numbers that were kept: {:n}", numbers);
}

std::vector<int> fillVector_1toN(int N)
{
  std::vector<int> numbers(static_cast<std::size_t>(N));
  std::iota(begin(numbers), end(numbers), 1);
  return numbers;
}
