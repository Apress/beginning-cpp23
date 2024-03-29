// Carton.cppm - defines the Carton class with the Box class as base
export module carton;

import std;
import box;

export class Carton : public Box
{
public:
  Carton() { std::println("Carton() called."); }

  explicit Carton(std::string_view material) : m_material{material}
  { std::println("Carton(string_view) called."); }

  Carton(double side, std::string_view material) : Box{side}, m_material{material}
  { std::println("Carton(double,string_view) called."); }

  Carton(double l, double w, double h, std::string_view material)
    : Box{l, w, h}, m_material{material}
    { std::println("Carton(double, double, double, string_view) called."); }

  // One new constructor
  Carton(double l, double w, double h, std::string_view m, double density, double thickness)
    : Carton{l, w, h, m} 
  {
    m_thickness = thickness; m_density = density;
    std::println("Carton(double, double, double, string_view, double, double) called.");
  }

  // Copy constructor
  Carton(const Carton& carton) : Box{carton}, m_material{carton.m_material},
     m_thickness{carton.m_thickness}, m_density{carton.m_density}
  {
     std::println("Carton copy constructor");
  }

  // Destructor
  ~Carton()
  {
    std::println("Carton destructor. Material = {}", m_material);
  }

  double getWeight() const
  {
    return 2.0 * (m_length * m_width + m_width * m_height + m_height * m_length) 
               * m_thickness * m_density;
  }

private:
  std::string m_material {"Cardboard"};
  double m_thickness {0.125};   // Material thickness in inch
  double m_density {0.2};       // Material density in pounds/cubic inch
};
