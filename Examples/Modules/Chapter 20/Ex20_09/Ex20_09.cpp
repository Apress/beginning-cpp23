// Inserting in and erasing from sequence containers
import std;

int main()
{
  std::vector numbers{ 2, 4, 5 };     // Deduced type: std::vector<int>
  numbers.insert(numbers.begin(), 1); // Add single element to the beginning of the sequence
  std::println("{}", numbers);        // [1, 2, 4, 5]

  numbers.insert(numbers.begin() + numbers.size() / 2, 3); // Add in the middle
  std::println("{}", numbers);   // [1, 2, 3, 4, 5]

  std::vector more_numbers{ 6, 7, 8 };
  numbers.insert(numbers.end(), more_numbers.begin(), more_numbers.end());
  std::println("{}", numbers);   // [1, 2, 3, 4, 5, 6, 7, 8]

  std::vector some_more{ 9, 10 };
  // numbers.insert(numbers.end(), some_more.begin(), some_more.end()); // Ugh
  // numbers.insert_range(numbers.end(), some_more);  // Shorter
  numbers.append_range(some_more);                    // Shortest 

  numbers.erase(numbers.end() - 5, numbers.end());     // Erase last 5 elements
  numbers.erase(numbers.begin() + numbers.size() / 2); // Erase the middle element
  numbers.erase(numbers.begin());                      // Erase the first element
  std::println("{}", numbers);   // [2, 4, 5]
}