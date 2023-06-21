// Sizing a pond for happy fish
import std;

int main()
{
  // 2 square feet pond surface for every 6 inches of fish
  const double fish_factor { 2.0/0.5 };  // Area per unit length of fish
  const double inches_per_foot { 12.0 };

  double fish_count {};            // Number of fish
  double fish_length {};           // Average length of fish

  std::print("Enter the number of fish you want to keep: ");
  std::cin >> fish_count;
  std::print("Enter the average fish length in inches: ");
  std::cin >> fish_length;
  fish_length /= inches_per_foot;  // Convert to feet
  std::println("");

  // Calculate the required surface area
  const double pond_area {fish_count * fish_length * fish_factor};

  // Calculate the pond diameter from the area
  const double pond_diameter {2.0 * std::sqrt(pond_area / std::numbers::pi)};

  // Convert to feet and inches
  const double pond_diameter_feet{ std::floor(pond_diameter) };
  const double pond_diameter_inch{
      std::round((pond_diameter - pond_diameter_feet) * inches_per_foot) };

  std::println("Pond diameter required for {} fish is {} feet {} inches.", 
               fish_count, pond_diameter_feet, pond_diameter_inch);
}
