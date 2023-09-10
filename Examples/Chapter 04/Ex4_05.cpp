// Using the if-else statement
import std;

int main()
{
  long number {};      // Stores input
  std::print("Enter an integer less than 2 billion: ");
  std::cin >> number;

  if (number % 2) // Test remainder after division by 2
  { // Here if remainder is 1
    std::println("Your number is odd.");
  }
  else
  { // Here if remainder is 0
    std::println("Your number is even.");
  }
}
