// A lambda expression returning the number of vector elements that begin with a given letter.

import std;

int main()
{
  std::vector<std::string> words{"apple", "pear", "plum", "orange", "peach", "grape", "greengage"};
  std::println("Words are: {}", words);

  const auto count {
    [&words](char letter)
    {
      std::size_t n {};
      for (auto& word : words)
        if (letter == word[0]) ++n;
      return n;
    }
  };
  
  char ch {'p'};
  std::println("There are {} words that begin with {}.", count(ch), ch);
  ch = 'g';
  std::println("There are {} words that begin with {}.", count(ch), ch);
}