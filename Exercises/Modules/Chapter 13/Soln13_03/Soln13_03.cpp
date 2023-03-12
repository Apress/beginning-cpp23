// Implementing the missing /, *=, +=, and /= operators for the Box class
import std;
import box;

int main()
{
  Box box {2, 3, 4};
  std::println("Box is {}", to_string(box));
  std::size_t n {3};
  box *= 3;
  std::println("After multiplying by {} box is {}", n, to_string(box));
  box /= 3;
  std::println("After dividing by {}, box is again {}", n, to_string(box));
  
  Box newBox {2 * box};
  std::println("Twice {} is {}", to_string(box), to_string(newBox));
  
  std::println("Half that is again {}", to_string(newBox / 2));
  
  std::println("Adding both boxes gives {}", to_string(box + newBox));
  
  box += newBox;
  
  std::println("The same can be obtained by usign += as well: {}", to_string(box));
}
