// Using a return statement to exit a switch statement
import std;

int main()
{
  char letter {};
  std::print("Enter a letter: ");
  std::cin >> letter;

  if (std::isalpha(letter))
  {
    switch (std::tolower(letter))
    {
    case 'a': case 'e': case 'i': case 'o': case 'u':
      std::println("You entered a vowel.");
      return 0;      // Ends the program
    }

    // We did not exit main() in the above switch, so letter is not a vowel:
    std::println("You entered a consonant.");
  }
  else
  {
    std::println("You did not enter a letter.");
  }
}
