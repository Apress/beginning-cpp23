// Overloading on const
import std;
import box;

int main()
{
  const Box constBox{ 1, 2, 3 };
  // constBox.length() = 2;                          // Does not compile: good!
  std::println("{}", constBox.length());

  Box nonConstBox{ 3, 2, 1 };
  nonConstBox.length() *= 2;
  std::println("{}", nonConstBox.length());
}
