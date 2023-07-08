// Searching a string for characters from a set
import std;

int main()
{
  std::string text;                                  // The string to be searched
  std::println("Enter some text terminated by *:\n");
  std::getline(std::cin, text, '*');

  const std::string separators{ " ,;:.\"!?'\n" };    // Word delimiters
  std::vector<std::string> words;                    // Words found
  auto start{ text.find_first_not_of(separators) };  // First word start index

  while (start != std::string::npos)                 // Find the words
  {
    auto end{ text.find_first_of(separators, start + 1) };// Find end of word
    if (end == std::string::npos)                         // Found a separator?
      end = text.length();                                // No, so set to end of text
    words.push_back(text.substr(start, end - start));     // Store the word
    start = text.find_first_not_of(separators, end + 1);  // Find first character of next word
  }

  std::println("Your string contains the following {} words:", words.size());
  unsigned count{};                                  // Number of printed strings
  for (const auto& word : words)
  {
    std::print("{:15}", word);
    if (!(++count % 5)) std::println("");
  }
  std::println("");

}
