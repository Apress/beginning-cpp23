// Implementing a destructor
import std;
import box;

int main()
{
  std::println("There are now {} Box objects.", Box::getObjectCount());

  const Box box1 {2.0, 3.0, 4.0};     // An arbitrary box
  Box box2 {5.0};                     // A box that is a cube

  std::println("There are now {} Box objects.", Box::getObjectCount());

  for (double d {} ; d < 3.0 ; ++d)
  {
    Box box {d, d + 1.0, d + 2.0};
    std::println("Box volume is {}", box.volume());
  }

   std::println("There are now {} Box objects.", Box::getObjectCount());

  auto pBox{ std::make_unique<Box>(1.5, 2.5, 3.5) };
  std::println("Box volume is {}", pBox->volume());
  std::println("There are now {} Box objects.", Box::getObjectCount());
}
