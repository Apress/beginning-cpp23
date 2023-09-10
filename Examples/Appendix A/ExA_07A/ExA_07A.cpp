// Calling external functions that are declared in a header file
import std;
#include "Power.h"

int main()
{
  for (int i {-3}; i <= 3; ++i)  // Calculate powers of 8 from -3 to +3
    std::println("{:10}", power(8.0, i));
}
