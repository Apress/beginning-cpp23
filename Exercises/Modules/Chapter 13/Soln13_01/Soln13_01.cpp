// Implementing the * operator for the Box class to post-multiply by an integer
import std;
import box;

int main()
{
  Box box {2, 3, 4};
  std::println("Box is {}", to_string(box));
  unsigned n {3};
  Box newBox{ box * n };
  std::println("After multiplying by {} box is {}", n, to_string(newBox));
}
