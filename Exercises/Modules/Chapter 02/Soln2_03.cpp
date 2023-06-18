// Compute the area of a circle
// This solution tunes the precision used when printing the result
// (we opted for 2 decimals after the decimal points).

import std;

int main()
{
  std::println("This program will compute the area of a circle.");

  double radius {};
  std::print("Please enter the radius of the circle: ");
  std::cin >> radius;
  
  const auto area{ std::numbers::pi * radius * radius };

  std::println("The area of the circle is {:.2f} square units.", area);
}