// Defining classes with in-class member definitions.

import std;
import box;        // For use of the Box class

int main()
{
  Box myBox{ 6.0, 6.0, 18.5 }; // Create a box
  std::println("Volume of the first Box object is {}", myBox.volume());
}