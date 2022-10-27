// Exercise 7-3 Replacing a word in text by asterisks.
// Because we are looking for the word regardless of case,
// the best way is to scan the text character by character.
import std;

int main()
{
  std::string text;     // The text to be searched
  std::string word;     // Stores the word to be replaced

  std::println("Enter some text terminated by *:");
  std::getline(std::cin, text, '*');
  std::print("\nEnter the word to be replaced: ");
  std::cin >> word;
  
  std::string lower_word;    // Convert word to lower case
  for (char ch : word)       // (we do so once, rather than with every iteration of the loop)
    lower_word += static_cast<char>(std::tolower(ch));

  const std::string separators {" ,;:.\"!?'\n"};            // Word delimiters

  std::size_t start {text.find_first_not_of(separators)};        // First word start index
  while (start != std::string::npos)                        // Find the words
  {
    auto end{ text.find_first_of(separators, start + 1) };  // Find end of word
    if (end == std::string::npos)                           // Found a separator?
      end = text.length();                                  // No, so set to last + 1

    // Compare the word found with lower_word
    if (end - start == word.length())
    {
      bool is_same_word{ true };                            // Assume it is the word we need to replace
      for (std::size_t i {start}; i < end; ++i)
      {
        if (lower_word[i - start] != std::tolower(text[i])) // If a character differs...
        {
          is_same_word = false;                             // ...it is not the word                                 
          break;      
        }
      }
      if (is_same_word)                                     // If it is the word...
      {
        for (std::size_t i {start}; i < end; ++i)           // ... replace by asterisks
          text[i] = '*';
      }
    }
    start = text.find_first_not_of(separators, end + 1);    // Find 1st character of next word
  }

  std::println("\n{}", text);
}
