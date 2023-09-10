// Using a local helper function with internal linkage (see Power.cpp)
import std;

extern double power(double x, int n);  // Declaration of an external power() function

int main()
{
  for (int i{ -3 }; i <= 3; ++i)  // Calculate powers of 8
    std::println("{:10}", power(8.0, i));
}
