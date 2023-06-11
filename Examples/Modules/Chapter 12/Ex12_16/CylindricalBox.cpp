module cylindrical;

import std;

CylindricalBox::CylindricalBox(float radius, float height, std::string_view material)
  : m_radius{ radius }
  , m_height{ height }
  , m_material{ material }
{
  std::print("Box constructed consisting of {}", material);
  if (material == s_default_material)
  {
    std::print(" (the default material!)");
  }
  std::println("");
}

float CylindricalBox::volume() const
{
  return PI * m_radius * m_radius * m_height;
}

