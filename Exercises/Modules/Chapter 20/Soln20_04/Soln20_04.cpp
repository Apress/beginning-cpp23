// Removing all elements that satisfy a certain condition using std::partition() / stable_partition().

/*
  Notes:
   - Normally one would use std::remove() (as this is slightly faster and more to the point),
     though std::partition() can be used for this as well.
   - You may notice that std::partition() reorders the elements that it keeps.
     It is implementation-defined whether this partition() preserves the original order or not.
     If you want to make sure the original order of the numbers is preserved,
     you need to use std::stable_partition()
*/
import std;

std::vector<int> fillVector_1toN(int N);  // Fill a vector with 1, 2, ..., N
void removeEvenNumbers(std::vector<int>& numbers);

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
  std::vector<int> numbers;
  for (int i{ 1 }; i <= N; ++i)
    numbers.push_back(i);
  return numbers;
}

void removeEvenNumbers(std::vector<int>& numbers)
{
  const auto first_even_number
    { std::stable_partition(begin(numbers), end(numbers), [](auto num) { return num % 2 == 1; }) };
  /*       ^^^^^^^^^^^^^^^^ if you use partition(), the order of the odd elements may become scrambled */ 
  
  numbers.erase(first_even_number, end(numbers));
}
