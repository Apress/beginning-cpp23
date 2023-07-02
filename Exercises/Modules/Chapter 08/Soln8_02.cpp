// Exercise 8-2 Reversing the order of a string of characters. 
/******************************************************************
The reverse() function works with an argument of type string, or a
C-style string terminated with '\0'.
*******************************************************************/
import std;

std::string reverse(std::string str);

int main()
{
  std::string sentence;
  std::println("Enter a sequence of characters, then press 'Enter':");
  getline(std::cin, sentence);

  std::println("\nYour sequence in reverse order is:\n{}", reverse(sentence));

  std::println("\nHere is a demonstration of reverse() working with a C-style string:");

  char stuff[] {"abcdefg"};                      // C-style string
  std::println(R"(The original string is: "{}")", stuff);
  std::println(R"(Reversed it becomes: "{}")", reverse(stuff));
}

// Reverse a string in place
// The code here is working with a copy of the argument
// so the original is not affected.
std::string reverse(std::string str)
{
  const std::size_t length {str.length()};
  for (std::size_t i {}; i < length / 2; ++i)
  {
    char temp{ str[i] };
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }
  return str;
}
