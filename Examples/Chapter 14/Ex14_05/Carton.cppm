// Carton.cppm - defines the Carton class with the Box class as base
export module carton;

import std;
import box;

export class Carton : public Box
{
  using Box::Box;  // Inherit Box class constructors 

public:
  Carton() = default;   // Required by Visual C++
  Carton(double length, double width, double height, std::string_view mat)
     : Box{length, width, height}, m_material{mat}
     { std::println("Carton(double, double, double, string_view) called."); }

private:
  std::string m_material {"Cardboard"};
};

