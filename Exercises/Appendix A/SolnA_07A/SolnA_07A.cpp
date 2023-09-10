// Exercise A-7   External variables (based on Exercise A-5)

// import std;  /* This does not work with Visual Studio 17 preview: using #include <print> instead... */
#include <print>

#include "PrintThis.h"
#include "PrintThat.h"

extern unsigned count;

int main()
{
  print_this("It is our choices that show what we truly are, ");
  print_that("far more than our abilities.");
                                          // -- Albus Dumbledore

  std::println("\n(print() was called {} times)", count);
}