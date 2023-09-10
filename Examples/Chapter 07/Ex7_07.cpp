// Replacing words in a string
import std;

int main()
{
  std::string text;                                   // The string to be modified
  std::println("Enter a string terminated by *:");
  std::getline(std::cin, text, '*');

  std::string word;                                   // The word to be replaced
  std::print("Enter the word to be replaced: ");
  std::cin >> word;

  std::string replacement;                            // The word to be substituted
  std::print("Enter the string to be substituted for {}: ", word);
  std::cin >> replacement;

  if (word == replacement)                            // Verify there's something to do
  {
    std::println("The word and its replacement are the same.\nOperation aborted.");
    return 1;
  }

  std::size_t start {text.find(word)};                 // Index of 1st occurrence of word
  while (start != std::string::npos)                   // Find and replace all occurrences
  {
    text.replace(start, word.length(), replacement);   // Replace word
    start = text.find(word, start + replacement.length());
  }

  std::println("\nThe string you entered is now:\n{}", text);
}
