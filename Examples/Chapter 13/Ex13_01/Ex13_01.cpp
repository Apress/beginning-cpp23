// Implementing a less-than operator
import std;
import box;

int main()
{
  std::vector boxes {Box {2.0, 2.0, 3.0}, Box {1.0, 3.0, 2.0},
                     Box {1.0, 2.0, 1.0}, Box {2.0, 3.0, 3.0}};
  Box smallBox {boxes[0]};
  for (const auto& box : boxes)
  {
    if (box < smallBox) smallBox = box;
  }

  std::println("The smallest box has dimensions {} x {} x {}", 
               smallBox.getLength(), smallBox.getWidth(), smallBox.getHeight());
}
