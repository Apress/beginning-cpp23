// More fun with formatting.
// You could always experiment further with various formatting options here!

import std;

int main()
{
  std::println("{:20} {:35} {}",        "Constant",            "Description",                       "Approximation");
  std::println("{:20} {:35} {:.5f}...", "std::numbers::e",     "The base of the natural logarithm", std::numbers::e);
  std::println("{:20} {:35} {:.5f}...", "std::numbers::pi",    "pi",                                std::numbers::pi);
  std::println("{:20} {:35} {:.5f}...", "std::numbers::sqrt2", "Square root of 2",                  std::numbers::sqrt2);
  std::println("{:20} {:35} {:.3f}...", "std::numbers::phi",   "The golden ratio constant",         std::numbers::phi);
  std::println("{:20} {:35} {:.5E}...", "sin(pi/4)",           "... in exponent notation",          std::sin(std::numbers::pi / 4));
}