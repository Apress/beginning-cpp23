// Output your BMI with one decimal after the decimal point.

import std;

int main()
{
  const double lbs_per_kg{ 2.2 };
  const double inches_per_foot{ 12.0 };
  const double meters_per_foot{ 0.3048 };

  double w_lbs{};
  unsigned int h_feet{};
  unsigned int h_inches{};

  std::print("Enter your weight in pounds: ");
  std::cin >> w_lbs;
  std::print("Enter you height in feet and inches: ");
  std::cin >> h_feet >> h_inches;

  const double w_kg{ w_lbs / lbs_per_kg };
  const double h_meters{ meters_per_foot * h_feet + h_inches / inches_per_foot };
  const double bmi{ w_kg / (h_meters * h_meters) };
  std::println("Your BMI is {:.1f}", bmi);
}