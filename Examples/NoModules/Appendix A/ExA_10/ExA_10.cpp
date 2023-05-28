// Including the same definitions twice
import std;
#include "BadMath.h"
#include "BadMath.h"

int main()
{
  std::println("{}", square(1.234));
}
