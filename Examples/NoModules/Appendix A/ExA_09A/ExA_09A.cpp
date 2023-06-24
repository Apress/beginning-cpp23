// Attempting to call a function with internal linkage from a different translation unit
import std;

double localHelper(double x, unsigned n); // Declares an external localHelper() function

int main()
{
  for (unsigned i{ 0 }; i <= 5; ++i)  // Calculate positive powers of 8
    std::println("{:10}", localHelper(8.0, i));
}
