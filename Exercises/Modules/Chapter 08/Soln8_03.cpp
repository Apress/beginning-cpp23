// Exercise 8_3 Checking the number of arguments entered at the command line. 
import std;

int main(int numArguments, char* arguments[])
{
  switch (numArguments - 1) // arguments[0] is the name of the program!
  {
  case 2: case 3: case 4:
    for (std::size_t i {1}; i < numArguments; ++i)
      std::println("Argument {} is {}", i, arguments[i]);
    break;
  default:
    std::println("You entered an incorrect number of arguments.\nPlease enter 2, 3, or 4 arguments.");
  }
}