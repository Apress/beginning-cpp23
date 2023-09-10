// Exercise 7-7
// Practice string concatenation, looping over strings, and stoi()-like functions
import std;

int main()
{
  std::println("Enter a sequence of numbers terminated by #:");
  
  // Read a long string containing any number of integers
  std::string numbers;
  std::getline(std::cin, numbers, '#');

  long sum {};
  
  std::size_t index {};
  while (true)  // An indefinite loop, stopped using a break statement.
  {
    // Note: this solution does not verify that in between the numbers there's only whitespace. 
    // In real programs, such input validation may be appropriate...

    // Search for the start of the next (signed!) number
    const std::size_t start{ numbers.find_first_of("-0123456789", index) };
    if (start == std::string::npos) 
      break;  // Stop once there's no numbers left

    // Search for the end of the number
    std::size_t end{ numbers.find_first_not_of("0123456789", start + 1) };
    if (end == std::string::npos)
      end = numbers.length();

    const std::size_t length{ end - start };   // To access substrings, we need the length of the string
    const auto substring{ numbers.substr(start, length) };

    // Just in case: skip minus signs not followed by a number (would otherwise crash...)
    if (substring != "-")
    {
      const int number{ std::stoi(substring) };

      sum += number;
    }
    
    index = end;   // Advance to the next input (if any)
  }
    
  std::println("The sum of the numbers you entered is: {}", sum);
}