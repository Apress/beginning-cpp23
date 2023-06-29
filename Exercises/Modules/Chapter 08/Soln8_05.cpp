// Exercise 8_5 Listing prime numbers
import std;

bool isPrime(unsigned number);

// Option 1: return vector<>
// Remember: starting with C++11, returning a vector is efficient. 
// In modern C++, this is therefore the recommended approach.
std::vector<unsigned> generateNumbers(unsigned to, unsigned from = 1);
std::vector<unsigned> filterPrimeNumbers(const std::vector<unsigned>& numbers);

/* 
// Option 2: vector<> output variables (not implemented)
// This is the traditional approach. 
// In modern C++, returning using return value is recommended.
void generateNumbers(std::vector<unsigned>& output, unsigned to, unsigned from = 1);
void filterPrimeNumbers(std::vector<unsigned>& output, const std::vector<unsigned>& numbers);
*/

int main()
{
  unsigned user_number{};
  std::print("Would you be so kind as to enter a number? ");
  std::cin >> user_number;
  
  const auto numbers{ generateNumbers(user_number) };
  const auto primes{ filterPrimeNumbers(numbers) };
  
  unsigned count{};
  for (auto& prime : primes)
  {
    std::print("{:8}", prime);
    if (++count % 15 == 0)
      std::println("");
  }
  
  std::println("");
}

/* 
  The sqrt() in the for loop below is not required. 
  The following loop would be equally correct, just a bit slower:
  
  for (unsigned i{ 2 }; i < number; ++i)
  {
    ...
  }
  
  It is a quite common optimisation though to stop testing at 
  the square root of the number. Think about why this is correct!
*/
bool isPrime(unsigned number)
{
  // a prime number is a natural number strictly greater than 1...
  if (number <= 1) return false;
  
  // ...and with no positive divisors other than 1 and itself
  for (unsigned i{ 2 }; i < std::sqrt(number); ++i)
  {
    if (number % i == 0)
    {
      return false;
    }
  }
  
  return true;
}

std::vector<unsigned> generateNumbers(unsigned to, unsigned from)
{
  std::vector<unsigned> result;
  for (unsigned i{ from }; i <= to; ++i)
    result.push_back(i);
  return result;
}

std::vector<unsigned> filterPrimeNumbers(const std::vector<unsigned>& numbers)
{
  std::vector<unsigned> result;
  for (auto number : numbers)
  {
    if (isPrime(number))
      result.push_back(number);
  }
  return result;
}