module box;
import std;

Box::Box(double length, double width, double height)  // Constructor definition
  : m_length{length}, m_width{width}, m_height{height}
{
  ++s_object_count;
  std::println("Box constructor 1 called.");
}

Box::Box(double side) : Box{side, side, side}  // Constructor for a cube
{
  // Do not increment s_object_count in forwarding constructor: 
  // already incremented in the constructor this constructor forwards to!
  std::println("Box constructor 2 called.");
}

Box::Box()                                      // Default constructor
{
  ++s_object_count;
  std::println("Default Box constructor called.");
}

Box::Box(const Box& box)                        // Copy constructor
  : m_length{box.m_length}, m_width{box.m_width}, m_height{box.m_height}
{
  ++s_object_count;
  std::println("Box copy constructor called.");
}

Box::~Box()                              // Destructor
{
  std::println("Box destructor called.");
  --s_object_count;
}
