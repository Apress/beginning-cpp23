// Defaulting the == operator
import std;
import box;

int main()
{
  const std::vector boxes {Box {2.0, 1.5, 3.0}, Box {1.0, 3.0, 5.0},
                           Box {1.0, 2.0, 1.0}, Box {2.0, 3.0, 2.0}};
  const Box theBox {3.0, 1.0, 4.0};

  for (const auto& box : boxes)
    if (theBox > box)     // > works
      std::println("{} is greater than {}", to_string(theBox), to_string(box));

  std::println("");

  for (const auto& box : boxes)
    if (theBox != box)    // != works
      std::println("{} is not equal to {}", to_string(theBox), to_string(box));

  std::println("");

  for (const auto& box : boxes)
    if (6.0 <= box)      // Yes, even double <= Box works!!
       std::println("6 is less than or equal to {}", to_string(box)); 
}
