// Creating a simply pseudo-random number generator (PRNG) functor class.
// Ours is a very limited one that generates numbers between 0 and 100.
// Seeding and using it requires some type conversions,
// but other than that our PRNG functor acts as a drop-in replacement to the original one!
import std;
import box;
import PRNG;

int main()
{
  std::random_device seeder;  // True random number generator to obtain a seed (slow)
  auto random{ PseudoRandomNumberGenerator{ static_cast<int>(seeder()) } };

  const std::size_t boxCount {20}; // Number of Box object to be created
  std::vector<Box> boxes;    // Vector of Box objects

  // Create 20 Box objects
  for (std::size_t i {}; i < boxCount; ++i)
    boxes.push_back(Box{ static_cast<double>(random()), static_cast<double>(random()), static_cast<double>(random()) });

  std::size_t first {};      // Index of first Box object of pair
  std::size_t second {1};    // Index of second Box object of pair
  double minVolume {(boxes[first] + boxes[second]).volume()};

  for (std::size_t i {}; i < boxCount - 1; ++i)
  {  
    for (std::size_t j {i + 1}; j < boxCount; j++)
    {
      if (boxes[i] + boxes[j] < minVolume)
      {
        first = i;
        second = j;
        minVolume = (boxes[i] + boxes[j]).volume();
      }
    }
  }

  std::println("The two boxes that sum to the smallest volume are {} and {}", 
               to_string(boxes[first]), to_string(boxes[second]));
  std::println("The volume of the first box is {:.1f}", boxes[first].volume());
  std::println("The volume of the second box is {:.1f}", boxes[second].volume());
  std::println("The sum of these boxes is {}", to_string(boxes[first] + boxes[second]));
  std::println("The volume of the sum is {:.1f}", minVolume);

  Box sum{ 0, 0, 0 };            // Start from an empty Box
  for (const auto& box : boxes)  // And then add all randomly generated Box objects
    sum += box;

  std::println("The sum of {} random boxes is {}", boxCount, to_string(sum));
}
