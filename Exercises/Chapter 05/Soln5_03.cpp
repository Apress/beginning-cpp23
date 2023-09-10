// Exercise 5-3 Using a do-while loop to count characters
import std;

int main()
{
  unsigned count {};
  char ch {};

  std::println("Please enter a sequence of characters terminated by '#':");

  // We have to read at least one character so do-while is best
  do
  {
    std::cin >> ch;
    ++count;
  } while (ch != '#');

  // We do not count '#' as a character, so count must be adjusted
  --count;
  std::println("You entered {} characters (not counting whitespace and the terminal #).", count);
}