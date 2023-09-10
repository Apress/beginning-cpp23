// Using an externally defined constant
import std;

extern double power(double x, int n);  // Declaration of an external power() function
extern const int power_range;          // Declaration of an external global constant

int main()
{
  for (int i {-power_range}; i <= power_range; ++i)  // Calculate powers of 8
    std::println("{:10}", power(8.0, i));
}
