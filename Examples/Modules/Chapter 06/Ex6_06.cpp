// Calculating primes using dynamic memory allocation
import std;

int main()
{
  unsigned max {};        // Number of primes required

  std::print("How many primes would you like? ");
  std::cin >> max;        // Read number required

  if (max == 0) return 0; // Zero primes: do nothing

  auto* primes {new unsigned long[max]};  // Allocate memory for max primes

  unsigned count {1};     // Count of primes found
  primes[0] = 2;          // Insert first seed prime

  unsigned long trial {3};     // Initial candidate prime

  while (count < max)
  {
    bool isprime {true};  // Indicates when a prime is found

    const auto limit{ static_cast<unsigned long>(std::sqrt(trial)) };
    for (unsigned i {}; primes[i] <= limit && isprime; ++i)
    {
      isprime = trial % primes[i] > 0;  // False for exact division
    }

    if (isprime)               // We got one...
      primes[count++] = trial; // ...so save it in primes array

    trial += 2;                // Next value for checking
  }

  // Output primes 10 to a line
  for (unsigned i{}; i < max; ++i)
  {
    std::print("{:10}", primes[i]);
    if ((i + 1) % 10 == 0)    // After every 10th prime...
      std::println("");       // ...start a new line
  }
  std::println("");

  delete[] primes;            // Free up memory...
  primes = nullptr;           // ... and reset the pointer
}
