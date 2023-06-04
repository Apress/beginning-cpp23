// Comparing array<> objects and plain arrays
import std;

int main()
{
  {
    std::println("First we try out the comparison operators for std::array<> objects:");
	
    std::array these {1.0, 2.0, 3.0, 4.0};
    std::array those {1.0, 2.0, 3.0, 4.0};
    std::array them  {1.0, 1.0, 5.0, 5.0};

    if (these == those) std::println("these and those are equal.");
    if (those != them)  std::println("those and them are not equal.");
    if (those > them)   std::println("those are greater than them.");
    if (them < those)   std::println("them are less than those.");
  }
  
  std::println("");
  
  {
	std::println("Next we repeat exactly the same comparisons with plain C++ arrays:");

    double these[] {1.0, 2.0, 3.0, 4.0};
    double those[] {1.0, 2.0, 3.0, 4.0};
    double them[]  {1.0, 1.0, 5.0, 5.0};

    if (these == those) std::println("these and those are equal.");
    if (those != them)  std::println("those and them are not equal.");
    if (those > them)   std::println("those are greater than them.");
    if (them < those)   std::println("them are less than those.");
  }
  
  /* The explanation of why this does not work as expected with plain arrays follows in Chapter 6 */
}

