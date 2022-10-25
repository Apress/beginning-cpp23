// Moving the implementation of functions from the module interface file 
// to a module implementation file.
import std;
import words;

int main()
{
  words::Words the_words;
  std::string text;                    // The string to be sorted
  const auto separators{" ,.!?\"\n"};  // Word delimiters

  // Read the string to be processed from the keyboard
  std::println("Enter a string terminated by *:");
  getline(std::cin, text, '*');

  words::extract_words(the_words, text, separators);
  if (the_words.empty())
  {
    std::println("No words in text.");
    return 0;
  }

  words::sort(the_words);         // Sort the words
  words::print_words(the_words);   // Output the words
}