// Multiple case actions
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
      break;
    default:
      std::println("You entered a consonant.");
      break;
    }
  }
  else
  {
    std::println("You did not enter a letter.");
  }
}
