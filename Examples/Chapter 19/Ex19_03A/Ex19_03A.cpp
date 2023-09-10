// Exercising the use of standard functors
import std;
import optimum;

int main()
{
  std::vector numbers{ 91, 18, 92, 22, 13, 43 };
  std::println("Minimum element: {}", *findOptimum(numbers, std::less<>{}));
  std::println("Maximum element: {}", *findOptimum(numbers, std::greater<>{}));
}
