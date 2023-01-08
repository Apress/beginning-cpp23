// Exercise 5-5 Print out characters entered by the user *after* reversing them
import std;

int main()
{
  const std::size_t max_num_characters {1'000};
  char string[max_num_characters];

  std::print("Please enter a string: ");
  std::cin.getline(string, max_num_characters);
  
  // Count the number of characters
  std::size_t count {};
  while (count < max_num_characters && string[count] != '\0') 
	  ++count;
  
  // Reverse the characters of the string entered by the user
  for (std::size_t i{ 0 }; i < count / 2; ++i)
  {
    char temp{ string[i] };
    string[i] = string[count - i - 1];
    string[count - i - 1] = temp;
  }
  
  // Print out all characters, one by one
  for (std::size_t i{ 0 }; i < count; ++i)
  {
    std::print("{}", string[i]);
  }
  std::println("");
}