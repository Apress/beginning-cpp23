// Exercise A-1   Defining a function-like macro

// import std;  /* This does not work with Visual Studio 17 preview: using #include <print> instead... */
#include <print>
#include "ASSERT.h"

int main()
{
  int y{ 5 };

  for (int x{}; x < 20; ++x)
  {
    std::println("x = {}\ty = {}", x, y);
    ASSERT(x < y, "Whoops-a-daisy, too far!");
  }
}