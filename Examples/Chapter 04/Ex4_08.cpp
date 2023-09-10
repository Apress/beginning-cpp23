// Using the switch statement
import std;

int main()
{
  std::println("Your electronic recipe book is at your service.");
  std::println("You can choose from the following delicious dishes:");
  std::println(" 1. Boiled eggs");
  std::println(" 2. Fried eggs");
  std::println(" 3. Scrambled eggs");
  std::println(" 4. Coddled eggs");

  std::print("\nEnter your selection number: ");
  int choice {};  // Stores selection value
  std::cin >> choice;

  switch (choice)
  {
  case 1:
    std::println("Boil some eggs.");
    break;
  case 2:
    std::println("Fry some eggs.");
    break;
  case 3:
    std::println("Scramble some eggs.");
    break;
  case 4:
    std::println("Coddle some eggs.");
    break;
    
  default:
    std::println("You entered a wrong number - try raw eggs.");
    break;
  }
}
