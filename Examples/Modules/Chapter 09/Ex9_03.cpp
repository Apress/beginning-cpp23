// Using std::string_view parameters
import std;

using std::string;
using std::string_view;
using std::vector;
using std::size_t;

void find_words(vector<string>& words, string_view text, string_view separators);
void list_words(const vector<string>& words);

int main()
{
  std::string text;         // The string to be searched
  std::println("Enter some text terminated by *:");
  std::getline(std::cin, text, '*');

  const std::string separators{ " ,;:.\"!?'\n" };  // Word delimiters
  std::vector<std::string> words;                 // Words found

  find_words(words, text, separators);
  list_words(words);
}

void find_words(vector<string>& words, string_view text, string_view separators)
{
  size_t start{ text.find_first_not_of(separators) }; // First word start index
  size_t end{};                                       // Index for end of a word

  while (start != string_view::npos)                  // Find the words
  {
    end = text.find_first_of(separators, start + 1);  // Find end of word
    if (end == string::npos)                          // Found a separator?
      end = text.length();                            // No, so set to end of text

    words.push_back(std::string{text.substr(start, end - start)});    // Store the word
    start = text.find_first_not_of(separators, end + 1); // Find 1st letter of next word
  }
}

void list_words(const vector<string>& words)
{
  std::println("Your string contains the following {} words:", words.size());
  size_t count{};                 // Number of outputted words
  for (const auto& word : words)
  {
    std::print("{:>15}", word);
    if (!(++count % 5))
      std::println("");
  }
  std::println("");
}
