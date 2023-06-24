import array;
import box;
import std;

int main()
{
  try
  {
    try
    {
      const std::size_t size {21};                         // Number of array elements
      const int start {-10};                               // Index for first element
      const int end {start + static_cast<int>(size) - 1};  // Index for last element

      Array<double, start> values {size};                  // Define array of double values

      for (int i {start}; i <= end; ++i)                   // Initialize the elements
        values[i] = i - start + 1;

      std::print("Sums of pairs of elements:");
      std::size_t lines {};
      for (int i {end}; i >= start; --i)
      {
        if (lines++ % 5 == 0) std::println("");
        std::print("{:5g}", values[i] + values[i-1]);
      }
    }
    catch (const std::out_of_range& ex)
    {
      std::println("\nout_of_range exception object caught! {}", ex.what());
    }

    // Create array of Box objects
    const int numBoxes {9};
    Array<Box, -numBoxes / 2> boxes { static_cast<std::size_t>(numBoxes) };    

    for (int i { -numBoxes / 2 }; i <= numBoxes/2 + numBoxes%2; ++i)
      std::println("Volume of Box[{}] is {}", i, boxes[i].volume());
  }
  catch (const std::exception& ex)
  {
    std::println("{} exception caught in main()! {}", typeid(ex).name(), ex.what());
  }
}
