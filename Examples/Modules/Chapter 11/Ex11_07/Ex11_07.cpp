// Separating declarations and definitions of functions
// declared in a namespace.
import std;
import math;

int main()
{
  const double values[]{ 10, 2, 1, 8, 3, 7, 4, 5, 6, 9 };
  std::println("Arithmetic mean: {}", math::averages::arithmetic_mean(values));
  std::println("Geometric mean: {}", math::averages::geometric_mean(values));
  std::println("Root mean square: {}", math::averages::rms(values));
  std::println("Median: {}", math::averages::median(values));
}
