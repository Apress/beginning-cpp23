// Using the std::isupper() / islower() character classification functions
import std;

int main()
{
  char letter {};                  // Store input here
  std::print("Enter a letter: ");  // Prompt for the input
  std::cin >> letter;

  if (std::isupper(letter))
  {
    std::println("You entered an uppercase letter.");
    return 0;
  }

  if (std::islower(letter))
  {
    std::println("You entered an lowercase letter.");
    return 0;
  }

  std::println("You did not enter a letter.");
}
