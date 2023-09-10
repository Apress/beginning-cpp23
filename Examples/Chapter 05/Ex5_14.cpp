// Using array<T,N> to create Body Mass Index (BMI) table
// BMI = weight/(height*height)
// weight in kilograms, height in meters

import std;

int main()
{
  const unsigned min_wt {100};     // Minimum weight in table (in pounds)
  const unsigned max_wt {250};     // Maximum weight in table
  const unsigned wt_step {10};
  const unsigned wt_count {1 + (max_wt - min_wt) / wt_step};

  const unsigned min_ht {48};      // Minimum height in table (inches)
  const unsigned max_ht {84};      // Maximum height in table
  const unsigned ht_step {2};
  const unsigned ht_count { 1 + (max_ht - min_ht) / ht_step };

  const double lbs_per_kg {2.2};   // Pounds per kilogram
  const double ins_per_m {39.37};  // Inches per meter
  std::array<unsigned, wt_count> weight_lbs {};
  std::array<unsigned, ht_count> height_ins {};

  // Create weights from 100lbs in steps of 10lbs
  for (unsigned i{}, w{ min_wt }; i < wt_count; w += wt_step, ++i)
  {
    weight_lbs[i] = w;
  }
  // Create heights from 48 inches in steps of 2 inches
  for (unsigned i{}, h{ min_ht }; h <= max_ht; h += ht_step)
  {
    height_ins.at(i++) = h;
  }
  // Output table headings
  std::print("{:>8}", '|');
  for (auto w : weight_lbs)
    std::print("{:^6}|", w);
  std::println("");
  
  // Output line below headings
  for (unsigned i{1}; i < wt_count; ++i)
    std::print("--------");
  std::println("");

  const unsigned inches_per_foot {12u};
  for (auto h : height_ins)
  {
    const unsigned feet = h / inches_per_foot;
    const unsigned inches = h % inches_per_foot;
    std::print("{:2}'{:2}\" |", feet, inches);

    const double h_m = h / ins_per_m;     // Height in meter
    for (auto w : weight_lbs)
    {
      const double w_kg = w / lbs_per_kg; // Weight in kilogram
      const double bmi = w_kg / (h_m * h_m);
      std::print(" {:2.1f} |", bmi);
    }
    std::println("");
  }
  // Output line below table
  for (std::size_t i {1}; i < wt_count; ++i)
    std::print("--------");
  std::println("\nBMI from 18.5 to 24.9 is normal");
}
