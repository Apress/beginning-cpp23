// Using the conditional operator to select output.
import std;

int main()
{
  int mice {};               // Count of all mice
  int brown {};              // Count of brown mice
  int white {};              // Count of white mice

  std::print("How many brown mice do you have? ");
  std::cin >> brown;
  std::print("How many white mice do you have? ");
  std::cin >> white;

  mice = brown + white;

  std::println("You have {} {} in total.", mice, mice == 1 ? "mouse" : "mice");
}
