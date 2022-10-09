// Obtaining the number of array elements
import std;

int main()
{
  int values[] {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

  std::println("There are {} elements in the array.", std::size(values));

  int sum {};
  const std::size_t old_school_size = sizeof(values) / sizeof(values[0]);
  for (std::size_t i {}; i < old_school_size; ++i)
  {
    sum += values[i];
  }
  std::println("The sum of the array elements is {}.", sum);
}
