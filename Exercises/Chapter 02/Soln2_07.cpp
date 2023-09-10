// Exercise 2-6. Format a table.

import std;

int main()
{
  std::println("{:20} {:35} {}",        "Constant",            "Description",                       "Approximation");
  std::println("{:20} {:35} {:.5f}...", "std::numbers::e",     "The base of the natural logarithm", std::numbers::e);
  std::println("{:20} {:35} {:.5f}...", "std::numbers::pi",    "pi",                                std::numbers::pi);
  std::println("{:20} {:35} {:.5f}...", "std::numbers::sqrt2", "Square root of 2",                  std::numbers::sqrt2);
  std::println("{:20} {:35} {:.3f}...", "std::numbers::phi",   "The golden ratio constant",         std::numbers::phi);
}