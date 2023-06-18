// Adding support for equality operators that compare Boxes and volumes
import std;
import box;

/*
  Because the compiler automatically rewrites != expression 
  in terms of == and/or even reverses the order of the operands,
  only one additional operator overload definition is required to make it all work.
*/

int main()
{
  Box box1{ 1, 2, 3 };
  Box box2{ 3, 2, 1 };
  Box box3{ 1, 2, 3 };

  // Try out all == and != operators (old and new, the latter in both directions)
  std::println("box1 and box2 are {}", box1 == box2 ? "equal" : "not equal");
  std::println("box1 and box3 are {}", box1 != box3 ? "not equal" : "equal");
  std::println("box1 is {} to 6.0", box1 == 6.0 ? "equal" : "not equal");
  std::println("10.0 is {} to box2", 10 != box2 ? "not equal" : "equal");
}
