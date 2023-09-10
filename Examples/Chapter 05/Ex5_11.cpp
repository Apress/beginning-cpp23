// Working with strings in an array
import std;

int main()
{
  const std::size_t max_length{80};    // Maximum string length (including \0)
  char stars[][max_length] {
                          "Fatty Arbuckle",  "Clara Bow",
                          "Lassie",          "Slim Pickens",
                          "Boris Karloff",   "Mae West",
                          "Oliver Hardy",    "Greta Garbo"
                        };
  std::size_t choice {};

  std::print("Pick a lucky star! Enter a number between 1 and {}: ", std::size(stars));
  std::cin >> choice;

  if (choice >= 1 && choice <= std::size(stars))
  {
    std::println("Your lucky star is {}", stars[choice - 1]);
  }
  else
  {
    std::println("Sorry, you haven't got a lucky star.");
  }
}