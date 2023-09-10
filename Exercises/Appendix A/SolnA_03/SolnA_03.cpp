// Exercise A-3   Writing an exception class that records where 
// the exception object was created/thrown.

// import std;  /* This does not work with Visual Studio 17 preview: using #include <print> instead... */
#include <print>
#include "SmarterException.h"

int main()
{
  try
  {
    throw SmarterException{ "Throwing directly..." };
  }
  catch (const SmarterException& exception)
  {
    std::println("Something went wrong at line {}", exception.where().line());
  }
}