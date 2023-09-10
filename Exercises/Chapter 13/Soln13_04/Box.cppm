export module box;

import std;

export class Box
{
public:
  // Constructors
  Box() = default;
  Box(double l, double w, double h) : m_length{ l }, m_width{ w }, m_height{ h } {}

  double volume() const { return m_length * m_width * m_height; }

  // Accessors
  double getLength() const { return m_length; }
  double getWidth()  const { return m_width; }
  double getHeight() const { return m_height; }

  auto operator<=>(const Box& otherBox) const 
  { 
    return volume() <=> otherBox.volume();
  }
  auto operator<=>(double otherVolume) const 
  { 
    return volume() <=> otherVolume;
  }

  bool operator==(const Box& otherBox) const = default;

  bool operator==(double otherVolume) const
  {
    return volume() == otherVolume;
  }

private:
  double m_length{ 1.0 };
  double m_width{ 1.0 };
  double m_height{ 1.0 };
};

export auto to_string(const Box& box)
{
    return std::format("Box({:.1f}, {:.1f}, {:.1f})",
                       box.getLength(), box.getWidth(), box.getHeight());
}