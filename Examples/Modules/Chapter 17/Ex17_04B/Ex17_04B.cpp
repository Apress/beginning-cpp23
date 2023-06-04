// Using a stack defined by nested class templates
// (using std::unique_ptr<>: see Stack<> source)
// Note: this is a bonus example that is only hinted at in the text (and not explicitly named). 
// It requires the use of std::move(), seen only in Chapter 18.
import stack;
import std;

int main()
{
  std::string words[] {"The", "quick", "brown", "fox", "jumps"};
  Stack<std::string> wordStack;            // A stack of strings

  for (const auto& word : words)
    wordStack.push(word);

  Stack<std::string> newStack{wordStack};  // Create a copy of the stack

  // Display the words in reverse order
  while (!newStack.isEmpty())
    std::print("{} ", newStack.pop());
  std::println("");

  // Reverse wordStack onto newStack
  while (!wordStack.isEmpty())
    newStack.push(wordStack.pop());

  // Display the words in original order
  while (!newStack.isEmpty())
    std::print("{} ", newStack.pop());
  std::println("");

  std::println("\nEnter a line of text:");
  std::string text;
  std::getline(std::cin, text); // Read a line into the string object

  Stack<char> characters;       // A stack for characters

  for (size_t i {}; i < text.length(); ++i)
    characters.push(text[i]);   // Push the string characters onto the stack

  std::println("");
  while (!characters.isEmpty())
    std::print("{}", characters.pop()); // Pop the characters off the stack

  std::println("");
}
