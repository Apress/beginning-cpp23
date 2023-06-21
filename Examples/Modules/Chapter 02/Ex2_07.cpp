// The width, alignment, fill, and 0 formatting options of std::println() 
import std;

int main()
{
  // Default alignment: right for numbers, left otherwise
  std::println("{:7}|{:7}|{:7}|{:7}", 1, -.2, "str", 'c');
  // Left and right alignment + custom fill character
  std::println("{:*<7}|{:*<7}|{:*>7}|{:*>7}", 1, -.2, "str", 'c');
  // 0 formatting option for numbers + centered alignment
  std::println("{:07}|{:07}|{:^7}|{:^7}", 1, -.2, "str", 'c');
}
