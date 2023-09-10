// Using a reference parameter
import std;

using std::string;
using std::vector;

void find_words(vector<string>& words, const string& str, const string& separators);
void list_words(const vector<string>& words);

int main()
{
  std::string text;         // The string to be searched
  std::println("Enter some text terminated by *:");
  std::getline(std::cin, text, '*');

  const std::string separators {" ,;:.\"!?'\n"};  // Word delimiters
  std::vector<std::string> words;                 // Words found

  find_words(words, text, separators);
  list_words(words);
}

void find_words(vector<string>& words, const string& text, const string& separators)
{
  std::size_t start {text.find_first_not_of(separators)};// First word start index

  while (start != std::string::npos)                     // Find the words
  {
    std::size_t end {text.find_first_of(separators, start + 1)}; // Find end of word
    if (end == string::npos)                             // Found a separator?
      end = text.length();                               // No, so set to end of text

    words.push_back(text.substr(start, end - start));    // Store the word
    start = text.find_first_not_of(separators, end + 1); // Find 1st character of next word
  }
}

void list_words(const vector<string>& words)
{
  std::println("Your string contains the following {} words:", words.size());
  unsigned count {};                 // Number of outputted words
  for (const auto& word : words)
  {
    std::print("{:>15}", word);
    if (!(++count % 5))
      std::println("");
  }
  std::println("");
}
