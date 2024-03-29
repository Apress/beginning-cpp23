// Exercise 8_8 More efficient recursive version of function for x to the power n, n positive or negative
// Based on Ex8_16.cpp
import std;

long double power(double x, int n);

int main()
{
  for (int i {-3}; i <= 3; ++i)     // Calculate powers of 8 from -3 to +3
    std::print("{:10g}", power(8.0, i));

  std::println("");
}

// Recursive function to calculate x to the power n
long double power(double x, int n)
{
  if (n == 0)     return 1.0;
  else if (n < 0) return 1.0 / power(x, -n);
  else if (n % 2) return x * power(x, n - 1);     // n is odd
  
  // If we make it this far, n > 0 and even
  const auto y{ power(x, n / 2) };
  return y * y;
}