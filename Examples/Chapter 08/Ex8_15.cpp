// Overloading a function with reference parameters
import std;

double larger(double a, double b); // Non-reference parameters
long& larger(long& a, long& b);    // Reference parameters

int main()
{
  double a_double {1.5}, b_double {2.5};
  std::println("The larger of double values {} and {} is {}",
               a_double, b_double, larger(a_double, b_double));

  int a_int {15}, b_int {25};
  std::println("The larger of int values {} and {} is {}", a_int, b_int, 
               larger(static_cast<long>(a_int), static_cast<long>(b_int)));
}

// Returns the larger of two floating point values
double larger(double a, double b)
{
  std::println("double larger() called.");
  return a > b ? a : b;
}

// Returns the larger of two long references
long& larger(long& a, long& b)
{
  std::println("long ref larger() called");
  return a > b ? a : b;
}
