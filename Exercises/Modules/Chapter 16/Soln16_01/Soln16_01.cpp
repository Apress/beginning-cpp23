// Throwing and catching Curveballs
import curveball;
import std;


void throwCurveballSometimes();           // First suggested solution
void throwCurveballSometimesBernouilli(); // Alternate solution

int main() 
{
  unsigned number {1'000'000};         // Number of loop iterations
  unsigned exceptionCount {};          // Count of exceptions thrown

  for (unsigned i {}; i < number; ++i)
  {
    try
    {
      throwCurveballSometimes();
      // throwCurveballSometimesBernouilli();
    }
    catch (const Curveball&)
    {
      exceptionCount++;
    }
  }
  
  std::println("Curveball exception thrown {} times out of {}.", exceptionCount, number);
}

// See Chapter 12 for an explanation of this function principle.
auto createUniformPseudoRandomNumberGenerator(int min, int max)
{
  std::random_device seeder;         // True random number generator to obtain a seed (slow)
  std::default_random_engine generator{ seeder() };     // Efficient pseudo-random generator
  std::uniform_int_distribution distribution{ min, max }; // Generate in [min, max] interval
  return std::bind(distribution, generator);            //... and in the darkness bind them!
}

// Throw a Curveball exception 25% of the time
void throwCurveballSometimes()
{
  static auto random{ createUniformPseudoRandomNumberGenerator(1, 100) };
  if (random() <= 25)
    throw Curveball{};
}

/*
 Alternate solution: instead of generating numbers in the interval [1,100]
 using a std::uniform_int_distribution and comparing against 25,
 you could also generate Boolean values directly using a std::bernoulli_distribution
 (see https://en.cppreference.com/w/cpp/numeric/random/bernoulli_distribution;
  named after https://en.wikipedia.org/wiki/Bernoulli_distribution):
*/
auto createUniformPseudoRandomBooleanGenerator(double probabilityOfTrue)
{
  std::random_device seeder;        // True random number generator to obtain a seed (slow)
  std::default_random_engine generator{ seeder() };    // Efficient pseudo-random generator
  std::bernoulli_distribution distribution{ probabilityOfTrue }; // The name says it all...
  return std::bind(distribution, generator);           //... and in the darkness bind them!
}

// Throw a Curveball exception 25% of the time
void throwCurveballSometimesBernouilli()
{
  static auto random{ createUniformPseudoRandomBooleanGenerator(0.25) };
  if (random())
    throw Curveball{};
}