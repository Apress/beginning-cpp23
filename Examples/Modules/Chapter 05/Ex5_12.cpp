// Allocating an array at runtime
// This example does not work with some compilers (such as Visual C++)
// because dynamic arrays is not standard C++ (it is valid C though).
import std;

#ifdef _MSC_VER   // See Appendix A for an explanation of preprocessing macros
  #error Visual Studio does not support variable length arrays (not standard C++)
#endif

int main()
{
  std::size_t count {};
  std::print("How many heights will you enter? ");
  std::cin >> count;
  int height[count];            // Create the array of count elements

  // Read the heights
  std::size_t entered {};
  while (entered < count)
  {
    std::print("Enter a height (in inches): ");
    std::cin >> height[entered];
    if (height[entered] > 0)    // Make sure value is positive
    {
      ++entered;
    }
    else
    {
      std::println("A height must be positive - try again.");
    }
  }

  // Calculate the sum of the heights
  unsigned int total {};
  for (std::size_t i {}; i < count; ++i)
  {
    total += height[i];
  }
  std::println("The average height is {:.1f}", static_cast<float>(total) / count);
}
