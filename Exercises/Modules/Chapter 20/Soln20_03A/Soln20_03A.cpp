// Exercise 20-3 Replacing custom container types with standard ones
/*
	The following replacements were made compared to Soln17_06.cpp:
		- SparseArray<LinkedList<T>> --> std::multimap<std::size_t, T>
	
	This means that compared to Soln20_03, we replaced std::map<Key, std::vector<Value>>
	with the more compact (and efficient) std::multimap<Key, Value>. 
  This data structure was less discussed in the main text (as it is less used in practice), 
  but is actually more appropriate here.

  At the bottom, there's two alternative loops: one close to the original one,
  and one that takes advantage of the fact that the keys in the multimap are sorted.
*/
import std;

int main()
{
  std::string text;                                // Stores input prose or poem
  std::println("Enter a poem or prose over one or more lines.\n"
               "Terminate the input with #:");
  getline(std::cin, text, '#');

  std::multimap<char, std::string> words;
  const std::string_view letters{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

  // Extract words and store in the appropriate list
  // A list in the SparseArray is selected by the index in letters of the first letter in a word.
  const std::string_view separators{ " \n\t,.\"?!;:" }; // Separators between words
  std::size_t start{};                                  // Start of a word
  std::size_t end{};                                    // separator position after a word
  while (std::string::npos != (start = text.find_first_not_of(separators, start)))
  {
    end = text.find_first_of(separators, start + 1);
    const auto word{ text.substr(start, end - start) };
    const auto letter{ static_cast<char>(std::toupper(word[0])) };
    words.insert({ letter, word });
    start = end;
  }

  // List the words in order 5 to a line
  const std::size_t perline{ 5 };

  /* Option 1: use a loop similar to the original one */
  for (char letter : letters)
  {
    if (!words.contains(letter))
      continue;

    std::size_t count{};        // Word counter
    // Retrieve the range of all words that begin with letter
    const auto [from, to] { words.equal_range(letter) };
    for (auto iter{ from }; iter != to; ++iter)
    {
      std::print("{} ", iter->second);
      if (++count % perline == 0)
        std::println("");
    }
    if (count % perline)
      std::println("");
  }

  std::println("");

  /* Option 2: take advantage of the fact that the keys are already sorted in the multimap */
  std::size_t count{};          // Word counter
  char previous_letter{};
  for (const auto& [letter, word] : words)
  {
    if (letter != previous_letter)
    {
      if (count % perline)  // Add line break after each new letter if need be
        std::println("");
      count = 0;            // Always reset counter
    }

    std::print("{} ", word);
    if (++count % perline == 0)
      std::println("");

    previous_letter = letter;
  }
  
  if (count % perline)
    std::println("");
}