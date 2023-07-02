// Calculating powers - rearranged
import std;

//double power(double x, int n);               // Function prototype - uncomment for successful compilation

int main()
{
  // Calculate powers of 8 from -3 to +3
  for (int i {-3}; i <= 3; ++i)
    std::print("{:10g}", power(8.0, i));

  std::println("");
}

// Function to calculate x to the power n
double power(double x, int n)
{
  double result{ 1.0 };
  if (n >= 0)
  {
    for (int i{ 1 }; i <= n; ++i)
      result *= x;
  }
  else // n < 0
  {
    for (int i{ 1 }; i <= -n; ++i)
      result /= x;
  }
  return result;
}

