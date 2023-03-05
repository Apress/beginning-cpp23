// Modifying the result of an overloaded subscript operator
import std;
import truckload;

/*
  Caution: in the text, we suggest to add 
    
    static SharedBox nullBox{};
  
  to the Truckload class definition. This will not compile.
  In-class definitions of non-const static members are only allowed
  if you add the inline keyword, as we did in this solution.
  See Chapter 12 for more explanation,
  and for the alternative of defining the member out-of-class.
*/

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
  auto random = createUniformPseudoRandomNumberGenerator(limit);

  Truckload load;
  const size_t boxCount {16};   // Number of Box object to be created

  // Create boxCount Box objects
  for (std::size_t i {}; i < boxCount; ++i)
    load.addBox(std::make_shared<Box>(random(), random(), random()));

  std::println("The boxes in the Truckload are:");
  load.printBoxes();

  // Find the largest Box in the Truckload
  double maxVolume {};
  size_t maxIndex {};
  size_t i {};
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

  load[0] = load[1];        // Copy 2nd element to the 1st
  std::println("\nAfter copying the 2nd element to the 1st, the list contains:");
  load.printBoxes();

  load[1] = std::make_shared<Box>(*load[2] + *load[3]);
  std::println("\nAfter making the 2nd element a pointer to the 3rd plus 4th, "
               "the list contains:");
  load.printBoxes();
}
