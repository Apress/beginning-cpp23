// Extracting all odd numbers.
import std;

std::set<int> fillSet_1toN(int N);  // Fill a set with 1, 2, ..., N

int main()
{
  const int num_numbers{20};

  const auto numbers{ fillSet_1toN(num_numbers) };

  std::vector<int> odd_numbers( numbers.size() ); // Caution: not { numbers.size() }!
  auto end_odd_numbers{ std::copy_if(begin(numbers), end(numbers), begin(odd_numbers),
                                     [](int n) { return n % 2 == 1; }) };
  odd_numbers.erase(end_odd_numbers, end(odd_numbers));

  std::println("The odd numbers are: {:n}", odd_numbers);
}

std::set<int> fillSet_1toN(int N)   // Fill a set with 1, 2, ..., N
{
  std::set<int> numbers;
  for (int i{ 1 }; i <= N; ++i)
    numbers.insert(i);
  return numbers;
}