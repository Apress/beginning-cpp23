export module boxes:carton;
import :box;
import std;

export class Carton : public Box
{
public:
  // Constructor explicitly calling the base constructor
  Carton(double l, double w, double h, std::string_view mat = "cardboard")
    : Box{l, w, h}, m_material{mat}
  {}

  ~Carton() { std::println("Carton destructor called"); }

  // Function to calculate the volume of a Carton object
  double volume() const override
  {
    return std::max(getLength() - 0.5, 0.0) 
         * std::max(getWidth() - 0.5, 0.0)
         * std::max(getHeight() - 0.5, 0.0);
  }

private:
  std::string m_material;
};
