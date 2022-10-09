// Comparing data values
import std;

int main()
{
  char first {};      // Stores the first character
  char second {};     // Stores the second character

  std::print("Enter a character: ");
  std::cin >> first;

  std::print("Enter a second character: ");
  std::cin >> second;

  std::println("The value of the expression {} < {} is {}", 
               first, second, first < second);
  std::println("The value of the expression {} == {} is {}", 
               first, second, first == second);
}
