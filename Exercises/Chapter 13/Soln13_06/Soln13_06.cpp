// Implementing the obvious operators for the Box class 
// to allow it to be used, for instance, in if statements.
// A Box is "true" if and only if its volume is non-zero.
import std;
import box;

void testBox(const Box& box)
{
  std::println("The box's volume is {}.", box.volume());
  if (box)
    std::println("This volume is non-zero.");
  if (!box)
    std::println("This volume is zero.");
}

int main()
{
  Box box1{2, 3, 4};
  std::println("box1 is {}", to_string(box1));
  testBox(box1);
  
  std::println("");

  Box box2{ 0, 0, 0 };
  std::println("box2 is {}", to_string(box2));
  testBox(box2);  
}
