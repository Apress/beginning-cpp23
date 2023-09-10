// Using an externally defined variable
import std;

/*extern*/ double power(double x, int n);  // Declaration of an external power() function
/*extern*/ int power_range;                // Not an unreasonable first attempt, right?

int main()
{
  for (int i {-power_range}; i <= power_range; ++i)  // Calculate powers of 8
    std::println("{:10}", power(8.0, i));
}
