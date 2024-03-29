export module box;

import std;

export class Box
{
public:
  Box() = default;
  Box(double length, double width, double height) 
    : m_length{length}, m_width{width}, m_height{height} {};

  double volume() const 
  {
    return m_length * m_width * m_height;
  }

  int compare(const Box& box) const
  {
    if (volume() < box.volume()) return -1;
    if (volume() == box.volume()) return 0;
    return +1;
  }

  friend auto to_string(const Box& box)
  {
    return std::format("Box({:.1f}, {:.1f}, {:.1f})", box.m_length, box.m_width, box.m_height);
  }

  Box operator+(const Box& aBox) const   // Function to add two Box objects
  {
    return Box{ std::max(m_length, aBox.m_length),
                std::max(m_width, aBox.m_width),
                m_height + aBox.m_height }; 
  }

private:
  double m_length {1.0};
  double m_width {1.0};
  double m_height {1.0};
};
