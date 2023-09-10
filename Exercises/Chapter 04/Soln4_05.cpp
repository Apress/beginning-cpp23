// Exercise 4-05
// Using the conditional operator to select output.
import std;

int main()
{
  int mice {};      // Count of all mice
  int brown {};     // Count of brown mice
  int white {};     // Count of white mice

  std::print("How many brown mice do you have? ");
  std::cin >> brown;
  std::print("How many white mice do you have? ");
  std::cin >> white;
  
  if (brown < 0 || white < 0)
  {
    std::println("One cannot have a negative amount of mice...");
    return 1;
  }

  mice = brown + white;

  std::println("You have {} {} in total.", mice, mice == 1 ? "mouse" : "mice");

  if (mice == 1)
  {
    std::println("It is a {} mouse.", brown ? "brown" : "white");
  }
  else
  {
    std::println("Of these mice, {} {} brown {}.", 
        brown, brown == 1 ? "is a" : "are", brown == 1 ? "mouse" : "mice");
  }
}
