// Using a friend function of a class
import std;
import box;

int main()
{
  Box box1 {2.2, 1.1, 0.5};    // An arbitrary box
  Box box2;                    // A default box
  auto box3{ std::make_unique<Box>(15.0, 20.0, 8.0) }; // Dynamically allocated Box

  std::println("Volume of box1 = {}", box1.volume());
  std::println("Surface area of box1 = {}", surfaceArea(box1));

  std::println("Volume of box2 = {}", box2.volume());
  std::println("Surface area of box2 = {}", surfaceArea(box2));

  std::println("Volume of box3 = {}", box3->volume());
  std::println("Surface area of box3 = {}", surfaceArea(*box3));
}

// friend function to calculate the surface area of a Box object
double surfaceArea(const Box& box)
{
  return 2.0 * (box.m_length * box.m_width 
                 + box.m_length * box.m_height + box.m_height * box.m_width);
}
