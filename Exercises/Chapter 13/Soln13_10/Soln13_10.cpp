// Adding an assignment operator for Truckload
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
  const double limit{ 99.0 };      // Upper limit on Box dimensions
  auto random{ createUniformPseudoRandomNumberGenerator(limit) };

  Truckload load;
  const std::size_t boxCount {20}; // Number of Box object to be created

  // Create boxCount Box objects
  for (std::size_t i {}; i < boxCount; ++i)
    load.addBox(std::make_shared<Box>(random(), random(), random()));

  std::println("The boxes in the Truckload are:");
  load.printBoxes();

  std::println("");

  Truckload copied;
  copied = load;		// Use copy assignment
  copied = copied;      // World does not end when attempting self-assignment
 
  std::println("The boxes in the copied Truckload are:");
  copied.printBoxes();
}
