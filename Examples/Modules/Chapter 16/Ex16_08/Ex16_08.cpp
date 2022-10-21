// Using an exception class
import std;
import box;

int main()
{
  try
  {
    Box box1 {1.0, 2.0, 3.0};
    std::println("box1 volume is {}", box1.volume());
    Box box2 {1.0, -2.0, 3.0};
    std::println("box2 volume is {}", box2.volume());
  }
  catch (const std::exception& ex)
  {
    std::println("Exception caught in main(): {}", ex.what());
  }
}
