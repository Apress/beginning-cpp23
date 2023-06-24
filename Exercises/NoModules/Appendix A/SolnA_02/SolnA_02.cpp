// import std;  /* This does not work with Visual Studio 17 preview: using #include <print> instead... */
#include <print>

// Define (before including ASSERT.h) to disable the assertion
#define NDEBUG
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