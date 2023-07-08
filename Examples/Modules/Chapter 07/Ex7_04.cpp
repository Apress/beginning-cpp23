// Searching within strings
import std;

int main()
{
  std::string sentence {"Manners maketh man"};
  std::string word {"man"};
  std::println("{}", sentence.find(word));  // Prints 15
  std::println("{}", sentence.find("Ma"));  // Prints 0
  std::println("{}", sentence.find('k'));   // Prints 10
  std::println("{}", sentence.find('x'));   // Prints std::string::npos
}
