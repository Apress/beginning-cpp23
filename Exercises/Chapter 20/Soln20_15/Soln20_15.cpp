// Implementing a custom std::formatter<> specialization to format Box objects
import box;
import box.formatter;
import std;

int main()
{
  Box box{ 1, 2, 3 };
  std::println("My new box, {:.2}, is fabulous!", box);
}