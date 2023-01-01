// Using a nested if
import std;

int main()
{
  char letter {};                      // Store input here
  std::print("Enter a letter: ");      // Prompt for the input
  std::cin >> letter;

  if (letter >= 'A')
  {                                    // letter is 'A' or larger
    if (letter <= 'Z')
    {                                  // letter is 'Z' or smaller
      std::println("You entered an uppercase letter.");
      return 0;
    }
  }

  if (letter >= 'a')                   // Test for 'a' or larger
    if (letter <= 'z')
    {                                  // letter is >= 'a' and <= 'z'
      std::println("You entered a lowercase letter.");
      return 0;
    }
  std::println("You did not enter a letter.");

}
