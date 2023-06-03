// Exercise A-4   Defining class member functions in the header

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

  // Advanced use. This was no requirement of the exercise, 
  // but it seems like something a smart exception could use...
  try
  {
    SmarterException exception{ "Throwing later...", {} };  // Optional: {} to avoid calling std::source_location::current()
    // ...
    exception.throwFromHere();
  }
  catch (const SmarterException& exception)
  {
    std::println("Something went wrong at line {}", exception.where().line());
  }
}