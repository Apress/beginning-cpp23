// Inline class member definitions (see Box.h)
import std;
#include "Box.h"

int main()
{
  Box boxy{ 1, 2, 3 };
  std::println("{}", boxy.volume());
}
