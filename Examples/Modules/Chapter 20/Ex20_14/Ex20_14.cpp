// Removing all elements that satisfy a certain condition 
// usign the remove-erase idiom
import std;

std::vector<int> fillVector_1toN(int N);  // Fill a vector with 1, 2, ..., N
void removeEvenNumbers(std::vector<int>& numbers);

int main()
{
  const int num_numbers{ 15 };

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
  // Use the remove_if() algorithm to remove all even numbers
  auto first_to_erase{ std::remove_if(begin(numbers), end(numbers),
                                      [](int number) { return number % 2 == 0; }) };
  // Erase all elements including and beyond first_to_erase  
  numbers.erase(first_to_erase, end(numbers));
}