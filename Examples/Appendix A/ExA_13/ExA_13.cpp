// Including a class definition from a header
import std;
#include "Box.h"

int main()
{
  Box boxy{ 1, 2, 3 };
  std::println("{}", boxy.volume());
}
