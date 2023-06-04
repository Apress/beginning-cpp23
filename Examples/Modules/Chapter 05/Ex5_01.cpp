// Using a for loop with an array
import std;

int main()
{
  const std::size_t size {6};                     // Array size
  unsigned height[size] {26, 37, 47, 55, 62, 75}; // An array of heights

  unsigned total {};                              // Sum of heights
  for (std::size_t i {}; i < size; ++i)
  {
    total += height[i];
  }

  const auto average{ static_cast<double>(total) / size }; // Calculate average height
  std::println("The average height is {:.1f}.", average);

  unsigned count {};
  for (std::size_t i {}; i < size; ++i)
  {
    if (height[i] < average) ++count;
  }
  std::println("{} people are below average height.", count);

}
