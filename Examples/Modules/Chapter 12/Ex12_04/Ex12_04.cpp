// Using the explicit keyword
// Uncomment "explicit" to make the compilation of 
// the expression "box1.hasLargerVolumeThan(50.0)" fail
import std;

class Cube
{
public:
  /*explicit*/ Cube(double side);       // Constructor
  double volume();                      // Calculate volume of a cube
  bool hasLargerVolumeThan(Cube cube);  // Compare volume of a cube with another
private:
  double m_side;
};

Cube::Cube(double side) : m_side{side}
{
  std::println("Cube constructor called.");
}

double Cube::volume() { return m_side * m_side * m_side; }
bool Cube::hasLargerVolumeThan(Cube cube) { return volume() > cube.volume(); }

int main()
{
  Cube box1 {7.0};
  Cube box2 {3.0};
  if (box1.hasLargerVolumeThan(box2))
    std::println("box1 is larger than box2.");
  else
    std::println("Volume of box1 is less than or equal to that of box2.");

  std::println("Volume of box1 is {}.", box1.volume());
  if (box1.hasLargerVolumeThan(50.0))
    std::println("Volume of box1 is greater than 50.");
  else
    std::println("Volume of box1 is less than or equal to 50.");
}
