export module box;

import std;

export class Box
{
public:
  // Constructors
  Box() = default;
  Box(double l, double w, double h) : m_length{ l }, m_width{ w }, m_height{ h } {}

  Box& operator++();         // Prefix ++operator
  const Box operator++(int); // Postfix operator++
  Box& operator--();         // Prefix --operator
  const Box operator--(int); // Postfix operator--

  double volume() const { return m_length * m_width * m_height; }

  // Accessors
  double getLength() const { return m_length; }
  double getWidth()  const { return m_width; }
  double getHeight() const { return m_height; }

  std::partial_ordering operator<=>(const Box& otherBox) const 
  { 
    return volume() <=> otherBox.volume();
  }
  std::partial_ordering operator<=>(double otherVolume) const 
  { 
    return volume() <=> otherVolume;
  }

  bool operator==(const Box& otherBox) const = default;

private:
  double m_length{ 1.0 };
  double m_width{ 1.0 };
  double m_height{ 1.0 };
};

Box& Box::operator++()   // Prefix ++operator
{
  ++m_length;
  ++m_width;
  ++m_height;
  return *this;
}

const Box Box::operator++(int)  // Postfix operator++
{
  auto copy{ *this };  // Create a copy of the current object
  ++(*this);           // Increment the current object using the prefix operator...
  return copy;         // Return the unincremented copy
}

Box& Box::operator--()   // Prefix --operator
{
  --m_length;
  --m_width;
  --m_height;
  return *this;
}

const Box Box::operator--(int)  // Postfix operator--
{
  auto copy{ *this };  // Create a copy of the current object
  --(*this);           // Decrement the current object using the prefix operator...
  return copy;         // Return copy of the original value
}

export std::string to_string(const Box& box)
{
    return std::format("Box({:.1f}, {:.1f}, {:.1f})",
        box.getLength(), box.getWidth(), box.getHeight());
}