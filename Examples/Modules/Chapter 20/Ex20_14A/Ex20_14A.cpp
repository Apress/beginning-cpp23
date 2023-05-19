// Removing all elements that satisfy a certain condition using std::erase_if()
import std;

std::vector<int> fillVector_1toN(int N);  // Fill a vector with 1, 2, ..., N
void removeEvenNumbers(std::vector<int>& numbers);

int main()
{
  const int num_numbers{ 20 };

  auto numbers{ fillVector_1toN(num_numbers) };

  std::println("The original set of numbers: {:n}", numbers);

  removeEvenNumbers(numbers);

  std::println("The numbers that were kept: {:n}", numbers);
}

std::vector<int> fillVector_1toN(int N)
{
  std::vector<int> numbers;
  for (int i{ 1 }; i <= N; ++i)
    numbers.push_back(i);
  return numbers;
}

void removeEvenNumbers(std::vector<int>& numbers)
{
  std::erase_if(numbers, [](int number) { return number % 2 == 0; });
}
