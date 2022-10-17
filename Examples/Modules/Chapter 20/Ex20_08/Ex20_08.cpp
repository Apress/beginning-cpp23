// Altering elements through a mutable iterator
import std;
import box; // From Ex11_04

int main()
{
  std::vector boxes{ Box{ 1.0, 2.0, 3.0 } }; // A std::vector<Box> containing 1 Box

  auto iter{ boxes.begin() };
  std::println("{} ", iter->volume());  // 6 == 1.0 * 2.0 * 3.0

  *iter = Box{ 2.0, 3.0, 4.0 };
  std::println("{} ", iter->volume());  // 24 == 2.0 * 3.0 * 4.0

  iter->setHeight(7.0);
  std::println("{} ", iter->volume());  // 42 == 2.0 * 3.0 * 7.0
}
