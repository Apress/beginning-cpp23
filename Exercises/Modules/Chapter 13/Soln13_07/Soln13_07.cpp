// In canonical C++, you should only implement a single operator to allow 
// objects to be used in if statements, and in Boolean expressions in general:
// a conversion operator for type bool.
//
// This conversion operator, moreover, is normally qualified as explicit.
// This is far from obvious: despite the explicit qualifier,
// objects still implicitly convert to bool in, for instance, if statements.
// As illustrated at the bottom of main(), however, 
// simply assigning a Box to a variable of type bool indeed no longer works
// without an explicit type conversion (in most cases this is the desired behavior).
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

  // bool b1{ box1 };    /* Does not compile! */
  [[maybe_unused]]  // Tip: [[maybe_unused]] attribute silences compiler warnings about not using b2
  bool b2{ static_cast<bool>(box2) };  // Needs an explicit type conversion
}
