// Creating multiple definitions of the same functions in a program,
// even though #include guards are present.
// (The guards only prevent multiple definitions within one translation unit!)
import std;
#include "Hypot.h"
#include "Pow4.h"

int main()
{
  std::println("{}\t{}", math::hypot(3, 4), math::pow4(5));
}
