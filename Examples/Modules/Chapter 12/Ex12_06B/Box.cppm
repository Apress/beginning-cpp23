export module box;
import std;

// Class to represent a box
export class Box
{
public:
  Box() = default;
  Box(double length, double width, double height)
    : m_length{ length }, m_width{ width }, m_height{ height }
  {
    std::cout << "Box constructor called." << std::endl;
  }

  // Function to calculate the volume of a box
  double volume() { return m_length * m_width * m_height; }

private:
  double m_length{ 1.0 };
  double m_width{ 1.0 };
  double m_height{ 1.0 };
};
