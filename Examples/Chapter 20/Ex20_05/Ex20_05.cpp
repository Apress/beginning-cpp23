// Working with maps
import std;

// Type aliases
using Words = std::vector<std::string_view>;
using WordCounts = std::map<std::string_view, std::size_t>;

// Function prototypes
Words extractWords(std::string_view text, std::string_view separators = " ,.!?\"\n");
WordCounts countWords(const Words& words);
void showWordCounts(const WordCounts& wordCounts);
std::size_t maxWordLength(const WordCounts& wordCounts);

int main()
{
  std::string text;    // The string to count words in

  // Read a string from the keyboard
  std::println("Enter a string terminated by *:");
  getline(std::cin, text, '*');

  Words words{ extractWords(text) };
  if (words.empty())
  {
    std::println("No words in text.");
    return 0;
  }

  WordCounts wordCounts{ countWords(words) };
  showWordCounts(wordCounts);
}

Words extractWords(std::string_view text, std::string_view separators)
{
  Words words;
  std::size_t start{ text.find_first_not_of(separators) }; // Start 1st word
  std::size_t end{};                                       // Index for the end of a word
                                                         
  while (start != std::string_view::npos)                
  {                                                      
    end = text.find_first_of(separators, start + 1);     // Find end separator
    if (end == std::string_view::npos)                   // End of text?
      end = text.length();                               // Yes, so set to last+1
    words.push_back(text.substr(start, end - start));    
    start = text.find_first_not_of(separators, end + 1); // Find next word
  }

  return words;
}

WordCounts countWords(const Words& words)
{
  WordCounts result;
  for (const auto& word : words)
    ++result[word];
  return result;
}

std::size_t maxWordLength(const WordCounts& wordCounts)
{
  std::size_t max{};
  for (const auto& [word, count] : wordCounts)
    if (count >= 2 && max < word.length()) max = word.length();
  return max;
}

void showWordCounts(const WordCounts& wordCounts)
{
  const std::size_t field_width{maxWordLength(wordCounts) + 1};
  const std::size_t words_per_line{5};

  std::size_t words_in_line{}; // Number of words in the current line
  char previous_initial{};
  for (const auto& [word, count] : wordCounts)
  {
    if (count <= 1) continue;  // Skip words that appear only once

    // Output newline when initial letter changes or after 5 per line
    if ( (previous_initial && word[0] != previous_initial)
          || words_in_line++ == words_per_line)
    {
      words_in_line = 0;
      std::println("");
    }
    // Output "word (count)", where word has a dynamic field width
    std::print("{:>{}} ({:2})", word, field_width, count); 
    previous_initial = word[0];
  }
  std::println("");
}
