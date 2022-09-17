// Using a for loop with an array
import <print>;

int main()
{
  const unsigned size {6};                        // Array size
  unsigned height[size] {26, 37, 47, 55, 62, 75}; // An array of heights

  unsigned total {};                              // Sum of heights
  for (std::size_t i {}; i < size; ++i)
  {
    total += height[i];
  }

  const unsigned average {total/size};            // Calculate average height
  std::println("The average height is {}.", average);

  unsigned count {};
  for (std::size_t i {}; i < size; ++i)
  {
    if (height[i] < average) ++count;
  }
  std::println("{} people are below average height.", count);

}
