// Throwing and catching Curveballs and throwing TooManyExceptions
import curveball;
import too_many;

import std;

void throwCurveballSometimes();

// This program will terminate abnormally when the TooManyExceptions exception is thrown.
int main()
{
  unsigned number{ 1'000 };            // Number of loop iterations
  unsigned exceptionCount {};          // Count of exceptions thrown
  const unsigned maxExceptions{ 10 };  // Maximum number of exceptions

  for (unsigned i {}; i < number; ++i)
  {
    try
    {
      throwCurveballSometimes();
    }
    catch (const Curveball& e)
    {
      std::println("{}", e.what());
    
      if (++exceptionCount > maxExceptions)
        throw TooManyExceptions{ maxExceptions };
    }
  }
}

// See Soln16_01 (to generate Booleans, a bernoulli_distribution is actually most appropriate)
auto createUniformPseudoRandomBooleanGenerator(double probabilityOfTrue)
{
  std::random_device seeder;        // True random number generator to obtain a seed (slow)
  std::default_random_engine generator{ seeder() };    // Efficient pseudo-random generator
  std::bernoulli_distribution distribution{ probabilityOfTrue }; // The name says it all...
  return std::bind(distribution, generator);           //... and in the darkness bind them!
}

// Throw a Curveball exception 25% of the time
void throwCurveballSometimes()
{
  static auto random{ createUniformPseudoRandomBooleanGenerator(0.25) };
  if (random())
    throw Curveball{};
}