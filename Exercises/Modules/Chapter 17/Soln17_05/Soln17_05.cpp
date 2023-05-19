// Exercising the SparseArray class template in combination with the LinkedList class template
import sparse_array;
import linked_list;
import std;

int main()
{
  std::string text;                                // Stores input prose or poem
  std::println("Enter a poem or prose over one or more lines.\n"
               "Terminate the input with #:");
  getline(std::cin, text, '#');

  SparseArray<LinkedList<std::string>> lists;      // Sparse array of linked lists
  const std::string_view letters {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

  // Extract words and store in the appropriate list
  // A list in the SparseArray is selected by the index in letters of the first letter in a word.
  const std::string_view separators {" \n\t,.\"?!;:"};  // Separators between words
  std::size_t start {};                                 // Start of a word
  std::size_t end {};                                   // separator position after a word
  while (std::string::npos != (start = text.find_first_not_of(separators, start)))
  {
    end = text.find_first_of(separators, start+1);
    const auto word{ text.substr(start, end - start) };
    const auto letter{ static_cast<char>(std::toupper(word[0])) };
    lists[letters.find(letter)].push_back(word);
    start = end;
  }

  // List the words in order 5 to a line
  const std::size_t perline {5};
  
  for (std::size_t i {}; i < std::size(letters); ++i)
  {
    if (!lists.element_exists_at(i))
      continue;
  
    std::size_t count {};         // Word counter
    for (auto iterator { lists[i].front_iterator() }; iterator; iterator.next())
    {
      std::print("{} ", iterator.value());
      if (++count % perline == 0)
        std::println("");
    }
    if (count % perline)
      std::println("");
  }
  std::println("");
}