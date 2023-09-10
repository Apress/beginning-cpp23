// Delegating constructors
import std;

class Box
{
public:
  Box(double length, double width, double height);
  explicit Box(double side);   // Constructor for a cube (explicit!)
  Box() = default;             // Defaulted default constructor

  double volume();             // Function to calculate the volume of a box

private:
  double m_length{1.0};
  double m_width {1.0};
  double m_height{1.0};
};

// A constructor that initializes all three member variables
Box::Box(double length, double width, double height) 
  : m_length{length}, m_width{width}, m_height{height}
{
  std::println("Box constructor 1 called.");
}

// This second constructor forwards to the first one to initialize all members.
// Note that you do not repeat the explicit keyword here!
Box::Box(double side) : Box{side, side, side}
{
  std::println("Box constructor 2 called.");
}

int main()
{
  Box box1 {2.0, 3.0, 4.0};     // An arbitrary box
  Box box2 {5.0};               // A box that is a cube
  std::println("box1 volume = {}", box1.volume());
  std::println("box2 volume = {}", box2.volume());
}

double Box::volume()
{
  return m_length * m_width * m_height;
}