// Exercise A-7   External variables (based on Exercise A-6)

// import std;  /* This does not work with Visual Studio 17 preview: using #include <print> instead... */
#include <print>

#include "PrintThis.h"
#include "PrintThat.h"
#include "Print.h"

int main()
{
  print_this("All we have to decide is what to do ");
  print_that("with the time that is given to us.");
                                 // -- Gandalf the Grey

  std::println("\n(print() was called {} times)", count);
}