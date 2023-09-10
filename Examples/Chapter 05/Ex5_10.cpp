// Classifying the letters in a C-style string
import std;

int main()
{
  const std::size_t max_length {100};   // Array size
  char text[max_length] {};     // Array to hold input string

  std::println("Enter a line of text:");

  // Read a line of characters including spaces
  std::cin.getline(text, max_length);
  std::println("You entered:\n{}", text);

  unsigned int vowels {};       // Count of vowels
  unsigned int consonants {};   // Count of consonants
  for (std::size_t i {}; text[i] != '\0'; i++)
  {
    if (std::isalpha(text[i]))  // If it is a letter...
    {
      switch (std::tolower(text[i]))
      {                         // ...check lowercase...
        case 'a': case 'e': case 'i': case 'o': case 'u':
          ++vowels;             // ...it is a vowel
          break;

        default:
          ++consonants;         // ...it is a consonant
      }
    }
  }
  std::println("Your input contained {} vowels and {} consonants.", 
               vowels, consonants);
}
