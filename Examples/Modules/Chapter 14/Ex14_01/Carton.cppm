// Carton.cppm - defines the Carton class with the Box class as base
export module carton;

import std;
import box;

export class Carton : public Box
{
public:
  explicit Carton(std::string_view material = "Cardboard")  // Constructor
    : m_material{material} {}

private:
  std::string m_material;
};

