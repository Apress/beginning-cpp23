// Floating-point control in a for loop
import <print>;
import <iostream>;
import <numbers>;

int main()
{
  const std::size_t values_per_line {3}; // Outputs per line
  std::size_t values_current_line {};    // Number of outputs on current line
  for (double radius {0.2}; radius <= 3.0; radius += 0.2)
  {
    const auto area = std::numbers::pi * radius * radius;
    std::print("radius = {:4.2f}, area = {:5.2f}; ", radius, area);
    if (++values_current_line == values_per_line)  // When enough values written...
    {
      std::println("");        // ...start a new line...
      values_current_line = 0; // ...and reset the line counter
    }
  }
  std::println("");
}
