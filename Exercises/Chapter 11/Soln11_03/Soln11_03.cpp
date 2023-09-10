// Splitting a module in multiple submodules
import words;

import std;

int main()
{
  words::Words the_words;
  std::string text;                    // The string to be sorted
  const auto separators{" ,.!?\"\n"};  // Word delimiters

  // Read the string to be processed from the keyboard
  std::println("Enter a string terminated by *:");
  getline(std::cin, text, '*');

  words::utils::extract_words(the_words, text, separators);
  if (the_words.empty())
  {
    std::println("No words in text.");
    return 0;
  }

  words::sorting::sort(the_words);         // Sort the words
  words::utils::print_words(the_words);   // Output the words
}