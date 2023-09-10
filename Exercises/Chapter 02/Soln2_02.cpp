// Convert SI to imperial weight
// The conversion values are constant, 
// and should not be changed within the program,
// so we recognize this by declaring them as a const.
//
// Note: we always output "pounds" even if it concerns only 1 pound.
// In a later chapter you will learn about the conditional 
// statements and expressions that allow you to refine this.

import std;

int main()
{
  const auto pounds_per_stone{ 14 };
  const auto kilogram_per_pound{ 0.45359237 };

  double kilogram{};
  std::print("May I be indiscreet and ask how much you weigh (in kg)? ");
  std::cin >> kilogram;

  const double pounds{ kilogram / kilogram_per_pound };
  const double stone{ std::floor(pounds / pounds_per_stone) };
  const double remaining_pounds{ std::fmod(pounds, pounds_per_stone) };
  // Or: remaining_pounds = pounds - stone * pounds_per_stone;
  
  // At this point you can either do the rounding of remaining_pounds yourself, 
  // or you can have std::println() do the rounding for you by using the appropriate precision.
  // Casting to an integer without rounding first is less appropriate, 
  // because you prefer nonintegral pounds to be rounded to the nearest integer.

  // Solution with performing the rounding yourself:
  const long integer_remaining_pounds{ std::lround(remaining_pounds) };
  std::println("Sounds less in imperial units: only {} stone {} pounds (using std::lround()).", stone, integer_remaining_pounds);

  // Solution with letting std::println() do the rounding for you:
  std::println("Sounds less in imperial units: only {} stone {:.0f} pounds (using :.0f format specifier).", stone, remaining_pounds);
}