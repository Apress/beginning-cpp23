// Exporting a class from a module
import std;
import box;          // For use of the Box class

int main()
{
  Box myBox{ 6.0, 6.0, 18.5 };   // Create a box
  std::println("Volume of the first Box object is {}", myBox.volume());
}
