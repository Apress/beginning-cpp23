// Using inline definitions to prevent ODR violations when
// including a header in multiple translation units of the same program.
import std;
#include "Hypot.h"
#include "Pow4.h"

int main()
{
  std::println("{}\t{}", math::hypot(3, 4), math::pow4(5));
}
