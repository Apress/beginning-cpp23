// Box.cppm - defines Box class
export module box;

import std;

export class Box
{
public:
  // Constructors
  Box(double l, double w, double h) : m_length{l}, m_width{w}, m_height{h}
  { std::println("Box(double, double, double) called."); }

  explicit Box(double side) : Box{side, side, side} 
  { std::println("Box(double) called."); }

  double volume() const { return m_length * m_width * m_height; }

  // Accessors
  double getLength() const { return m_length; }
  double getWidth()  const { return m_width; }
  double getHeight() const { return m_height; }

private:
  Box() { std::println("Box() called."); }   // Default constructor (made private)

  double m_length {1.0};
  double m_width {1.0};
  double m_height {1.0};
};
