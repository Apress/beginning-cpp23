// Exercise 20-2
// Replace a custom stack container by the standard stack container adapter
import std;

/*
  Two challenges:
  - std::stack<>::pop() is a void function. 
    To access the top of the stack, you use std::stack<>::top().
  - std::stack<const T> is not allowed
*/

int main()
{
  std::string words[]{ "The", "quick", "brown", "fox", "jumps" };
  std::stack<std::string> wordStack;              // A stack of strings

  for (const auto& word : words)
    wordStack.push(word);

  std::stack<std::string> newStack{ wordStack };  // Create a copy of the stack

  // Display the words in reverse order
  while (!newStack.empty())
  {
    std::print("{} ", newStack.top());
    newStack.pop();
  }
    
  std::println("");

  // Reverse wordStack onto newStack
  while (!wordStack.empty())
  {
    newStack.push(wordStack.top());
    wordStack.pop();
  }

  // Display the words in original order
  while (!newStack.empty())
  {
    std::print("{} ", newStack.top());
    newStack.pop();
  }
    
  std::println("");

  std::println("\nEnter a line of text:");
  std::string text;
  std::getline(std::cin, text);    // Read a line into the string object

  std::stack<char> characters;     // A stack for characters

  // Alternative to loop: characters.push_range(text);
  for (std::size_t i{}; i < text.length(); ++i)
    characters.push(text[i]);      // Push the string characters onto the stack
    
  std::println("");
  while (!characters.empty())
  {
    std::print("{}", characters.top()); // Pop the characters off the stack
    characters.pop();
  }

  std::println("");
}