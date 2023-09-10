// Concatenating characters and strings
// (exactly the same as Ex07_01, except that we use ' ' and '.' instead of " " and ".") 
import std;

int main()
{
  std::string first;                             // Stores the first name
  std::string second;                            // Stores the second name

  std::print("Enter your first name: ");
  std::cin >> first;                             // Read first name

  std::print("Enter your second name: ");
  std::cin >> second;                            // Read second name

  std::string sentence {"Your full name is "};   // Create basic sentence
  sentence += first + ' ' + second + '.';        // Augment with names

  std::println("{}", sentence);      // Print the sentence and its length
  std::println("The string contains {} characters.", sentence.length());
}
