// Using a derived class copy constructor
import std;
import carton;

int main()
{
  // Declare and initialize a Carton object
  Carton carton{ 20.0, 30.0, 40.0, "Expanded polystyrene" };
  std::println("");

  Carton cartonCopy{ carton };  // Use copy constructor
  std::println("");

  std::println("Volume of carton is {}", carton.volume());
  std::println("Volume of cartonCopy is {}", cartonCopy.volume());
}

