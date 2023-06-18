module box;

import std;

double Box::volume() const
{
    return m_length * m_width * m_height;
}

Box Box::operator+(const Box& aBox) const
{
  // New object has larger length and width, and sum of heights
  return Box{ std::max(m_length, aBox.m_length),
              std::max(m_width, aBox.m_width),
              m_height + aBox.m_height };
}

Box Box::operator*(double factor) const
{
  // New object has adjusted height
  return Box{ m_length, m_width, m_height * factor };
}

Box operator*(double factor, const Box& box)
{
  // Or: return box * factor;
  return Box{ box.getLength() * factor, box.getWidth() * factor, box.getHeight() * factor };
}

std::partial_ordering Box::operator<=>(const Box& aBox) const
{
  return volume() <=> aBox.volume();
}

std::partial_ordering Box::operator<=>(double value) const
{
  return volume() <=> value;
}

std::string to_string(const Box& box)
{
    return std::format("Box({:.1f}, {:.1f}, {:.1f})",
                       box.getLength(), box.getWidth(), box.getHeight());
}