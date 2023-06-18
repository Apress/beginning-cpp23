// Using the overloaded 'less-than' operators for Box objects
import std;
import box;

int main()
{
  std::vector boxes {Box {2.0, 2.0, 3.0}, Box {1.0, 3.0, 2.0},
                     Box {1.0, 2.0, 1.0}, Box {2.0, 3.0, 3.0}};
  const double minVolume{6.0};

  std::println("Objects with volumes less than {} are:", minVolume);
  for (const auto& box : boxes)
    if (box < minVolume) std::println("{}", to_string(box));

  std::println("Objects with volumes greater than {} are:", minVolume);
  for (const auto& box : boxes)
    if (minVolume < box) std::println("{}", to_string(box));
}
