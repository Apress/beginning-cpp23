// Exercising the SparseArray class template
// We create a sparse array of integers, populate 20 of its entries 
// (checking for duplicates among the randomly generated indices)
// and output the resulting index/value pairs.

import sparse_array;
import std;


// See Chapter 12 for an explanation of this principle.
// The difference here is that we need a std::uniform_int_distribution 
// instead of a std::uniform_real_distribution to generate integers instead 
// of float-point (or, "real") numbers.
auto createUniformPseudoRandomNumberGenerator(int min, int max)
{
  std::random_device seeder;         // True random number generator to obtain a seed (slow)
  std::default_random_engine generator{ seeder() };     // Efficient pseudo-random generator
  std::uniform_int_distribution distribution{ min, max }; // Generate in [min, max) interval
  return std::bind(distribution, generator);            //... and in the darkness bind them!
}

int main()
{
  const unsigned count {20};     // Number of elements to be created
  const int min_value{32};
  const int max_value{212};
  const std::size_t max_index{499};
  
  // Create the (pseudo)-random number generators 
  // (we use +1 because these generate integers in a half-open interval [min,max)...)
  auto generate_random_index{ createUniformPseudoRandomNumberGenerator(0, max_index + 1) };
  auto generate_random_value{ createUniformPseudoRandomNumberGenerator(min_value, max_value + 1) };

  SparseArray<int> numbers;               // Create empty sparse array
  
  for (unsigned i {}; i < count; ++i)       // Create count entries in numbers array
  {
    std::size_t index {};                 // Stores new index value

    // Must ensure that indexes after the first are not duplicates
    do
    {
      index = generate_random_index();    // Get a random index 0 to max_index
    }
    while (numbers.elementExistsAt(index));

    numbers[index] = generate_random_value();  // Store value at new index position
  }

  for (std::size_t i {}; i <= max_index; ++i)  // Check which elements exist in the numbers array
  {
    if (numbers.elementExistsAt(i))
      std::println("Element at index {} equals {}", i, numbers.at(i));
  }
}