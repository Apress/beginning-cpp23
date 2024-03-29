// Exercising the use of a functor as callback functions
import std;
import optimum;
import less;

template <typename T>
bool greater(const T& one, const T& other) { return one > other; }

int main()
{
  Less less;     // Create a 'less than' functor

  std::vector numbers{ 91, 18, 92, 22, 13, 43 };
  std::println("Minimum element: {}", *findOptimum(numbers, less));
  std::println("Maximum element: {}", *findOptimum(numbers, greater<int>));
}
