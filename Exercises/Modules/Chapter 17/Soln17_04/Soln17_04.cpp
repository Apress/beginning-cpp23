// Exercising the LinkedList template class
// This program reverses the text that is entered
import linked_list;
import std;

int main()
{
  std::string text;                            // Stores input prose or poem
  std::println("Enter a poem or prose over one or more lines.\n"
               "Terminate the input with #:");
  getline(std::cin, text, '#');

  LinkedList<std::string> words;               // List to store words

  // Extract words and store in the list
  std::string_view separators{ " ,.\"?!;:\n" };// Separators between words
  std::size_t start {};                        // Start of a word
  std::size_t end {};                          // separator position after a word
  while (std::string::npos != (start = text.find_first_not_of(separators, start)))
  {
    end = text.find_first_of(separators, start+1);
    words.push_back(text.substr(start,end-start));
    start = end;
  }

  // List the words 5 to a line
  std::println("\nThe words are:\n");
  auto iterator{ words.front_iterator() };
  std::size_t count {};            // Word counter
  const std::size_t perline {5};   // Worde per line
  while (iterator.hasValue())
  {
    std::print("{} ", iterator.value());
    if (!(++count % perline))
      std::println("");
    iterator.next();
  }
  std::println("");

  // List the words in reverse order 5 to a line
  std::println("\nIn reverse order, the words are:\n");
  iterator = words.back_iterator();
  count = 0;
  while (iterator.hasValue())
  {
    std::print("{} ", iterator.value());
    if(!(++count % perline))
      std::println("");
    iterator.previous();
  }
  std::println("");
}