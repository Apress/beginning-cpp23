module box;
import std;

Box::Box(double length, double width, double height)  // Constructor definition
  : m_length{length}, m_width{width}, m_height{height}
{
  std::println("Box constructor 1 called.");
}

Box::Box(double side) : Box{side, side, side}  // Constructor for a cube
{
  std::println("Box constructor 2 called.");
}

Box::Box()                                      // Default constructor
{
  std::println("Default Box constructor called.");
}

Box::Box(const Box& box)                        // Copy constructor
  : m_length{box.m_length}, m_width{box.m_width}, m_height{box.m_height}
{
  std::println("Box copy constructor called.");
}