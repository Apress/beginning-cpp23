// Fixed-point formatting of floating-point numbers with std::println()
import std;

int main()
{
  // 2 square feet pond surface for every 6 inches of fish
  const double fish_factor { 2.0/0.5 };       // Area per unit length of fish
  const unsigned int inches_per_foot { 12 };  // <-- Used to be of type double

  unsigned int fish_count {};  // Number of fish <-- Used to be of type double
  double fish_length {};       // Average length of fish

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

  std::println("Pond diameter required for {} fish is {:.2f} feet.",
               fish_count, pond_diameter);
}
