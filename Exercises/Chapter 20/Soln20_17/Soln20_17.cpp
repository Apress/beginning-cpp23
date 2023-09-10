// Implementing a custom std::formatter<> specialization to format Box objects
import std;
import box;
import box.formatter;

int main()
{
  Box box{ 1, 2, 3 };
  std::println("My new box, {:.2}, is fabulous!", box);
  std::println("It has these dimensions: {:.2n}", box);
}