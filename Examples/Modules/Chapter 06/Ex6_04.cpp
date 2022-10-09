// Using an array of pointers
import std;

int main()
{
  const char* pstars[] {
                         "Fatty Arbuckle", "Clara Bow", "Lassie", 
                         "Slim Pickens", "Boris Karloff", "Mae West",
                         "Oliver Hardy", "Greta Garbo"
                       };

  std::print("Pick a lucky star! Enter a number between 1 and {}: ", std::size(pstars));
  unsigned choice {};
  std::cin >> choice;

  if (choice >= 1 && choice <= std::size(pstars))
  {
    std::println("Your lucky star is {}.", pstars[choice - 1]);
  }
  else
  {
    std::println("Sorry, you haven't got a lucky star.");
  }
}

