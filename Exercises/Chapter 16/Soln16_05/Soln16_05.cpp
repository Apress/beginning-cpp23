// Exercise 16-5
/* Somewhat artificial example to practice lists of different, 
 * related exception types (mind the order + catch-by-reference!)
 * and rethrowing (catch-by-reference + "throw;" !)
 */

import std;
import curveball;
import domain_exceptions;

void askEvenNumber();           // Ask the user to provide an even number

int main()
{
  try
  {
    askEvenNumber();
  }
  catch (const Curveball& /*caught*/)
  {
    std::println("...hit it out of the park!");
  }
}

/* Helper functions for askEvenNumber() */
void throwCurveballSometimes(); // Throw a Curveball exception 25% of the time
int readEvenNumber();           // Reads an even number from std::cin and verifies the input 
                                // (throws upon failure)

// Option 1: use recursion
void askEvenNumber()
{
  try
  {
    std::print("Please enter an even number: ");
    const int read{ readEvenNumber() };
    std::println("Well done. {} is a beautiful even number. Thank you!", read);
  }
  catch (const NotANumber& nan)
  {
    std::println("{}", nan.what());
    return;
  }
  catch (const std::domain_error& domainException)
  {
    std::println("{}", domainException.what());
    askEvenNumber();  // Recursive call
  }
  catch (const std::exception& exception)
  {
    std::println("{}", exception.what());
    throw;
  }
}

/*
// Option 2: use a loop
void askEvenNumber()
{
  while (true)
  {
    try
    {
      std::print("Please enter an even number: ");
      const int read{ readEvenNumber() };
      std::println("Well done. {} is a beautiful even number. Thank you!", read);
      break;
    }
    catch (const NotANumber& nan)
    {
      std::println("{}", nan.what());
      return;
    }
    catch (const std::domain_error& domainException)
    {
      std::println("{}", domainException.what());
    }
    catch (const std::exception& exception)
    {
      std::println("{}", exception.what());
      throw;
    }
  }
}
*/

int readEvenNumber()
{
  int number;
  std::cin >> number;
  if (std::cin.fail()) // Check whether the user has effectively entered a number
  {
    std::cin.clear();  // Reset the stream's failure state
    std::string line;  // Read the erroneous input and discard it
    std::getline(std::cin, line);
    throw NotANumber{line};
  }
  
  throwCurveballSometimes();
  
  if (number < 0)
    throw NegativeNumber{number};
  if (number % 2)
    throw OddNumber{number};

  return number;
}

// See Soln16_01 for an explanation of this function
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