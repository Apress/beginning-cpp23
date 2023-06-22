export module box;

import std;

export class Box
{
public:
  Box() = default;       // Default constructor
  Box(double length, double width, double height)
    : m_length{ std::max(length,width) }
    , m_width { std::min(length,width) }
    , m_height{ height } 
  {}

  double volume() const; // Function to calculate the volume
  
  // Accessors
  double getLength() const { return m_length; }
  double getWidth() const  { return m_width; }
  double getHeight() const { return m_height; }

  bool operator==(const Box& aBox) const = default;

private:
  double m_length {1.0};
  double m_width {1.0};
  double m_height {1.0};
};

// Conversion to string
export std::string to_string(const Box& box)
{
    return std::format("Box({:.1f}, {:.1f}, {:.1f})",
        box.getLength(), box.getWidth(), box.getHeight());
}