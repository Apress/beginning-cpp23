// Searching within substrings
import std;

#include <version>  // To allow testing if :? is supported already (later addition to the library)

int main()
{
  std::string text;          // The string to be searched
  std::string word;          // Substring to be found
  std::println("Enter the string to be searched and press Enter:");
  std::getline(std::cin, text);

  std::println("Enter the string to be found and press Enter:");
  std::getline(std::cin, word);

  size_t count{};            // Count of substring occurrences
  size_t index{};            // String index
  while ((index = text.find(word, index)) != std::string::npos)
  {
    ++count;
    index += word.length();  // Advance by full word (discards overlapping occurrences)
  }

#ifdef __cpp_lib_format_ranges
  std::println("Your text contained {} occurrences of {:?}.", count, word);
#else // :? not supported: fall back to adding the double quotes ourselves...
  std::println("Your text contained {} occurrences of \"{}\".", count, word);
#endif
}
