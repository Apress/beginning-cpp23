// Using function pointers as callback functions
import std;
import optimum;

// Comparison function prototypes:
bool less(const int&, const int&);
template <typename T> bool greater(const T&, const T&);
bool longer(const std::string&, const std::string&);

int main()
{
  std::vector<int> numbers{ 91, 18, 92, 22, 13, 43 };
  std::println("Minimum element: {}", *findOptimum(numbers, less));
  std::println("Maximum element: {}", *findOptimum(numbers, greater<int>));

  std::vector<std::string> names{ "Moe", "Larry", "Shemp", "Curly", "Joe", "Curly Joe" };
  std::println("Alphabetically last name: {}", *findOptimum(names, greater<std::string>));
  std::println("Longest name: {}", *findOptimum(names, longer));
}

bool less(const int& one, const int& other) { return one < other; }

template <typename T>
bool greater(const T& one, const T& other) { return one > other; }

bool longer(const std::string& one, const std::string& other)
{
  return one.length() > other.length();
}
