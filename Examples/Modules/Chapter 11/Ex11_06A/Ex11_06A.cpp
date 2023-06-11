// Defining and using a namespace
import std;
import squaring;

int main()
{
  std::println("math::sqrt2 has the value {}", math::sqrt2);
  std::println("Squared that number equals {}", math::square(math::sqrt2));
  std::println("This should be 0: {}", math::sqrt2 - std::numbers::sqrt2);
}
