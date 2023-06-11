// Creating an array of objects
import std;
import box;

int main()
{
  const Box box1 {2.0, 3.0, 4.0};  // An arbitrary box
  Box box2 {5.0};                  // A box that is a cube
  std::println("box1 volume = {}", box1.volume());
  std::println("box2 volume = {}", box2.volume());
  Box box3 {box2};
  std::println("box3 volume = {}", box3.volume());   // Volume = 125

  std::println("");

  Box boxes[6] {box1, box2, box3, Box {2.0}};
}
