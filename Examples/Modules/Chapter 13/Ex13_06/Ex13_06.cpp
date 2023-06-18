// Using the addition operator for Box objects
import std;
import box;

// See Chapter 12 for an explanation of this function
auto createUniformPseudoRandomNumberGenerator(double max)
{
  std::random_device seeder;        // True random number generator to obtain a seed (slow)
  std::default_random_engine generator{ seeder() };    // Efficient pseudo-random generator
  std::uniform_real_distribution distribution{ 1.0, max }; // Generate in [1, max) interval
  return std::bind(distribution, generator);           //... and in the darkness bind them!
}

int main()
{
  const double limit {99};    // Upper limit on Box dimensions
  auto random { createUniformPseudoRandomNumberGenerator(limit) };

  const std::size_t boxCount {20}; // Number of Box objects to be created
  std::vector<Box> boxes;          // Vector of Box objects

  // Create 20 Box objects
  for (std::size_t i {}; i < boxCount; ++i)
    boxes.push_back(Box{ random(), random(), random() });

  std::size_t first {};            // Index of first Box object of pair
  std::size_t second {1};          // Index of second Box object of pair
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
