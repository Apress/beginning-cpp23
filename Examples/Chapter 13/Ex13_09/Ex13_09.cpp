// Overloading pre- and postfix increment and decrement operators
import std;
import box;

int main()
{
  Box theBox{ 3.0, 1.0, 3.0 };

  std::println("Our test Box is {}", to_string(theBox));

  std::println("Postfix increment evaluates to the original object: {}",
               to_string(theBox++));
  std::println("After postfix increment: {}", to_string(theBox));

  std::println("Prefix decrement evaluates to the decremented object: {}", 
               to_string(--theBox));
  std::println("After prefix decrement: {}", to_string(theBox));
}
