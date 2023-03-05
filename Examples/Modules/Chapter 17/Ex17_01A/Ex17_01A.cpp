// Using a class template
import box;
import array;
import std;

int main()
{
  try
  {
    const size_t numValues {20};
    Array<double> values {numValues};

    for (unsigned i {}; i < numValues; ++i)
      values[i] = i + 1;

    std::print("Sums of pairs of elements:");
    size_t lines {};
    for (std::size_t i {numValues - 1}; i >= 0; --i)
    {
      if (lines++ % 5 == 0) std::println("");
      std::print("{:5g}", values[i] + values[i-1]);
    }
  }
  catch (const std::out_of_range& ex)
  {
    std::println("\nout_of_range exception object caught! {}", ex.what());
  }

  try
  {
    const size_t numBoxes {5};
    Array<Box> boxes {numBoxes};
    for (std::size_t i {} ; i <= numBoxes ; ++i)
      std::println("Box volume is {}", boxes[i].volume());
  }
  catch (const std::out_of_range& ex)
  {
    std::println("\nout_of_range exception object caught! {}", ex.what());
  }
}
