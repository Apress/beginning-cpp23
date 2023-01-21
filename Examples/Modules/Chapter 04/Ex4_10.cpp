// Switching on enumerations
import std;

int main()
{
  enum class Color { red, green, blue };
  
  Color my_color = Color::red;
  
  std::print("Today, I'm feeling ");
  switch (my_color)
  {
  case Color::red:   std::println("loving"); break;
  case Color::green: std::println("jealous"); break;
  case Color::blue:  std::println("sad"); break;
  }
}