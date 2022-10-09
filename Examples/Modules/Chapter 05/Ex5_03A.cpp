// Floating-point control in a for loop:
// dangers of floating-point representation errors.
import std;

int main()
{
  for (double radius{ 0.2 }; radius <= 3.0; radius += 0.2)
  {
    std::println("radius = {:4.2f}, area = {:5.2f}, (radius + 0.2) = 3.0 + {}",
      radius,
      std::numbers::pi * radius * radius,
      (radius + 0.2) - 3.0
    );
  }
}
