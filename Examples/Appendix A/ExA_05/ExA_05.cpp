// Demonstrating assertions
import std;
#include <cassert>   // import <cassert>; is not guaranteed to work...

int main()
{
  int y {5};

  for (int x {}; x < 20; ++x)
  {
    std::println("x = {}\ty = {}", x, y);
    assert(x < y);
  }
}

// A static assertion (comment out to build as a 32-bit program)
static_assert(sizeof(int*) > 4, "32-bit compilation is not supported.");