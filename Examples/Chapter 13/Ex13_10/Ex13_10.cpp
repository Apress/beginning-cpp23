// Using the subscript operator
import std;
import truckload;

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
  const double limit {99.0};    // Upper limit on Box dimensions
  auto random{ createUniformPseudoRandomNumberGenerator(limit) };

  Truckload load;
  const std::size_t boxCount {16};   // Number of Box objects to be created

  // Create boxCount Box objects
  for (std::size_t i {}; i < boxCount; ++i)
    load.addBox(std::make_shared<Box>(random(), random(), random()));

  std::println("The boxes in the Truckload are:");
  load.printBoxes();

  // Find the largest Box in the Truckload
  double maxVolume {};
  std::size_t maxIndex {};
  std::size_t i {};
  while (load[i])
  {
    if (*load[i] > maxVolume)
    {
      maxIndex = i;
      maxVolume = load[i]->volume();
    }
    ++i;
  }

  std::println("\nThe largest box is: {}", to_string(*load[maxIndex]));

  load.removeBox(load[maxIndex]);

  std::println("\nAfter deleting the largest box, the Truckload contains:");
  load.printBoxes();
}
