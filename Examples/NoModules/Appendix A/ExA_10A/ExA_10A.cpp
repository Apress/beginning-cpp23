// Including the same header twice in the same translation unit without violating ODR
import std;
#include "BetterMath.h"
#include "BetterMath.h"

int main()
{
  std::println("{}", square(1.234));
}
