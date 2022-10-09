// Using an if statement
import std;

int main()
{
  std::print("Enter an integer between 50 and 100: ");
  int value {};
  std::cin >> value;

  if (value)
    std::println("You have entered a value that is different from zero.");

  if (value < 50)
    std::println("The value is invalid - it is less than 50.");

  if (value > 100)
    std::println("The value is invalid - it is greater than 100.");

  std::println("You entered {}.", value);
}
