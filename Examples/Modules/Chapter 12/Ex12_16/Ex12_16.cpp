// Defining and using static constants
import std;
import cylindrical;

int main()
{
  CylindricalBox bigBox{ 1.23f,
            CylindricalBox::s_max_height, CylindricalBox::s_default_material };
  std::println("The volume of bigBox is {}", bigBox.volume());
}
