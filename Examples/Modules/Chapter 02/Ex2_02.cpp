// Converting distances
import std;

int main()
{
  unsigned int yards {}, feet {}, inches {};

  // Convert a distance in yards, feet, and inches to inches
  std::print("Enter a distance as yards, feet, and inches ");
  std::println("with the three values separated by spaces: ");
  std::cin >> yards >> feet >> inches;

  const unsigned feet_per_yard {3};
  const unsigned inches_per_foot {12};

  unsigned total_inches {};
  total_inches = inches + inches_per_foot * (yards*feet_per_yard + feet);
  std::println("This distance corresponds to {} inches.", total_inches);

  // Convert a distance in inches to yards, feet, and inches
  std::print("Enter a distance in inches: ");
  std::cin >> total_inches;
  feet   = total_inches / inches_per_foot;
  inches = total_inches % inches_per_foot;
  yards  = feet / feet_per_yard;
  feet   = feet % feet_per_yard;
  std::println("This distance corresponds to {} yards {} feet {} inches.",
               yards, feet, inches);
}
