module box;

import std;

// Constructor definition
Box::Box(double length, double width, double height)
  : m_length{ length }, m_width{ width }, m_height{ height }
{
  std::println("Box constructor called.");
}

// Const member function definition
double Box::volume() const
{
  return m_length * m_width * m_height;
}

// Modify mutable member variable from a const member function 
void Box::printVolume() const
{
  // Count how many times printVolume() is called using a mutable member in a const function
  std::println("The volume of this box is {}", volume());
  std::println("printVolume() has been called {} time(s)", ++m_count);
}
