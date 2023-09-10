// A Quicksort function template

import std;

template <typename T>
void sort(std::vector<T>& data);
template <typename T>
void print(const std::vector<T>& data, unsigned width = 5);

int main()
{
  std::println("Sorting integers:");
  std::vector numbers{ -2, 4, -5, 6, 10, -40, 56, 4, 67, 45 };
  print(numbers);
  sort(numbers);
  print(numbers);

  std::println("\nSorting characters:");
  std::vector letters{ 'C', 'd', 'a', 'z', 't', 'S', 'p', 'm', 'D', 'f' };
  print(letters, 2);
  sort(letters);
  print(letters, 2);

  std::println("\nSorting floating-point values:");
  std::vector values{ -2.5, 1.4, 3.1415, -2.55, 6.3, 10.1, -40.5, 56.0, 4.7, 67.3, 45.0, 2.34567 };
  print(values, 9);
  sort(values);
  print(values, 9);
}

template <typename T>
void swap(std::vector<T>& data, std::size_t first, std::size_t second)
{
  auto temp{data[first]};
  data[first] = data[second];
  data[second] = temp;
}

template <typename T>
void sort(std::vector<T>& data, std::size_t start, std::size_t end)
{
  // start index must be less than end index for 2 or more elements
  if (start >= end)
    return;

  // Choose middle address to partition set
  swap(data, start, (start + end) / 2);    // Swap middle element with start element

  // Check data against chosen element
  std::size_t current {start};
  for (std::size_t i {start + 1}; i <= end; i++)
  {
    if (data[i] < data[start])     // Is element less than chosen element?
      swap(data, ++current, i);    // Yes, so swap to the left
  }

  swap(data, start, current);      // Swap chosen and last swapped elements

  if (current > start) sort(data, start, current - 1); // Sort left subset if exists
  if (end > current + 1) sort(data, current + 1, end); // Sort right subset if exists
}

// Sort data in ascending sequence
template <typename T>
void sort(std::vector<T>& data)
{
  if (!data.empty())
    sort(data, 0, data.size() - 1);
}

template <typename T>
void print(const std::vector<T>& data, unsigned width)
{
  const unsigned elements_per_line{ std::max(1u, 80u / width) };  // Avoid 0...

  unsigned elements_in_line{};  // Number of elements in current line
  for (const auto& element : data)
  {
    std::print("{:{}}", element, width); // Output an element
    if (++elements_in_line == elements_per_line)
    {
        elements_in_line = 0;
        std::println("");
    }
  }
  if (elements_in_line)
  {
    std::println("");
  }
}