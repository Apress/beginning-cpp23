// Using std::span<const T> to ensure largest() works for const inputs
import std;

// Old function prototypes
//double largest(const double data[], std::size_t count);
//double largest(const std::vector<double>& data);
//int largest(const std::vector<int>& data);
//std::string largest(const std::vector<std::string>& words);

// New function prototypes
// (these functions work for any sequential input, not just arrays or vectors)
double largest(std::span<const double> data);
int largest(std::span<const int> data);
std::string largest(std::span<const std::string> words);

int main()
{
  const double array[] {1.5, 44.6, 13.7, 21.2, 6.7};
  const std::vector numbers {15, 44, 13, 21, 6, 8, 5, 2};
  const std::vector data{3.5, 5.0, 6.0, -1.2, 8.7, 6.4};
  const std::array array_data{ 3.5, 5.0, 6.0, -1.2, 8.7, 6.4 }; // Throwing in an std::array for good measure
  const std::vector<std::string> names {"Charles Dickens", "Emily Bronte", 
                                  "Jane Austen", "Henry James", "Arthur Miller"};
  std::println("The largest of array is {}", largest(array));
  std::println("The largest of numbers is {}", largest(numbers));
  std::println("The largest of data is {}", largest(data));
  std::println("The largest of array_data is (also) {}", largest(array_data));
  std::println("The largest of names is {}", largest(names));
}

// Finds the largest of a sequence of double values
double largest(std::span<const double> data)
{
  double max {data[0]};
  for (auto value : data)
    if (max < value) max = value;
  return max;
}

// Finds the largest of a sequence of int values
int largest(std::span<const int> data)
{
  int max {data[0]};
  for (auto value : data)
    if (max < value) max = value;
  return max;
}

// Finds the largest of a sequence of std::string values
std::string largest(std::span<const std::string> words)
{
  std::string max_word {words[0]};
  for (const auto& word : words)
    if (max_word < word) max_word = word;
  return max_word;
}
