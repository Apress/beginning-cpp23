// Exercise 7-4 Check for anagrams.
// There's more than one way to do this. 
// We chose to delete characters in one word that are common to both.
// If the length of the word that has characters deleted is zero, they are anagrams.
import std;

int main() 
{
  std::string word1, word2;

  std::print("Enter the first word: ");
  std::cin >> word1;
  std::print("Enter the second word: ");
  std::cin >> word2;

  // Test the pathological case of the strings being different lengths
  if (word1.length() != word2.length())
  {
    std::println("{} and {} are different lengths so they can't be anagrams!", word1, word2);
    return 0;
  }

  std::string word2_copy {word2};                // Copy word2 - because we will delete characters
  // Loop over all the characters in word1
  for (char c : word1)
  {
    // Loop over all the characters in word2 (we need the index now, so a range-based for loop won't do)
    for (std::size_t i {}; i < word2_copy.length(); ++i)
    {
      if (std::tolower(word2_copy[i]) == std::tolower(c)) 
      {
        word2_copy.erase(i, 1);                  // Character found so erase from word2
        break;                                   // Caution: do not use erase(i), because that erases the entire substring starting at index i!
      }
    }
  }

  std::println("{} and {} {} anagrams of one another", 
      word1, word2, (word2_copy.empty() ? "are" : "are not"));
}