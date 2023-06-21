// Writing values of variables to the screen
import std;

int main()
{
  int apple_count {15};                            // Number of apples
  int orange_count {5};                            // Number of oranges
  int total_fruit {apple_count + orange_count};    // Total number of fruit

  std::println("The value of apple_count is {}", apple_count);
  std::println("The value of orange_count is {}", orange_count);
  std::println("The value of total_fruit is {}", total_fruit);
}
