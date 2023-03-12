// Implementing the * operator for the Box class to pre-multiply by a number
import std;
import box;

int main()
{
  Box box {2, 3, 4};
  std::println("Box is {}", to_string(box));
  unsigned n {3};
  Box newBox{ n * box };
  std::println("After pre-multiplying by {} box is {}", n, to_string(newBox));
}
