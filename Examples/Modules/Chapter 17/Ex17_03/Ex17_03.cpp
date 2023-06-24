// Illustrating Class Template Argument Deduction (CTAD) 
// by adding an initializer list constructor to our Array<> template.
import box;
import array;
import std;

int main()
{
  // Class Template Argument Deduction (CTAD) in action:
  Array integers{ 1, 2, 3, 4, 5 };           // Deduced type: Array<int>
  Array doubles{ 1.0, 2.0, 3.0, 4.0, 5.0 };  // Deduced type: Array<double

  // But... caution!
  {
    const std::size_t numValues{ 20 };
    Array<double> values{ numValues };  // Now uses the initializer list constructor!

    std::println("Wrong constructor used, so the Array's size, {}, is not {}", values.getSize(), numValues);
    std::println("Single value contained in Array<> is {}", values[0]);
  }

  // Workaround: do not use uniform initialization (or "near uniform", as is thus more appropriate...)
  { 
    const std::size_t numValues{ 20 };
    Array<double> values(numValues);    // Uses Array(std::size_t) constructor as before

    std::println("Intended constructor used, so the Array's size is {}", values.getSize());
    std::println("All values are equal to {}", values[numValues / 2]);
  }
}
