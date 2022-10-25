// Defining functions in module implementation files
import std;
import roman;

int main()
{
  std::println("1234 in Roman numerals is {}", to_roman(1234));
  std::println("MMXXIII in Arabic numerals is {}", from_roman("MMXXIII"));
}
