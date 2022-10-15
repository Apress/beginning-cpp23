// Exercise 6-3. Storing numbers in a dynamic array
// Btw: notice anything about the result? 
// Try increasing numbers of array elements...

/*
    Caution: the following seemingly reasonable loop leads to an end-result that is infinity
    for larger values of n (say n equal to 100,000):

    for (unsigned i {}; i < n; ++i)
      *(values+i) = 1.0 / ((i + 1)*(i + 1));
    
    Why? Take a second to think about it...
    The only elementary operation that, 
    if neither of the operands is infinity, leads to infinity is division-by-zero.
    And once an infinity value enters a sum, the end result remains infinity.
    
    So, next question: how can ((i + 1)*(i + 1)) be zero? 
    If the unsigned type is not large enough to represent the result, of course.
    To see why, you could run the following loop

    for (unsigned i{}; i < 100000; ++i)
      if ((i + 1) * (i + 1) == 0)
        std::println("(i + 1) * (i + 1) == 0 for i == {}", i);

    The output will likely be:

        (i + 1) * (i + 1) == 0 for i == 65535

    Here 65535 is, not coincidentally, equal to 2^16 - 1,
    which means that (65535 + 1) * (65535 + 1) equal to 2^32, a power of 2 that should ring a bell...
    Note that this also means that for any number larger than 65535,
    the result of (i + 1) * (i + 1) would also not be correct anymore.
    In other words: this division-by-zero-leading-to-infinity bug would be somewhat of a blessing,
    as it is far easier to discover than any other wrong results due to integer overflow!

    The solution we went with was to use a larger integer type, unsigned long long.
    But another interesting alternative would be to cast the integer to double before performing the computation:

    for (unsigned i {}; i < n; ++i)
      *(values+i) = 1.0 / ((static_cast<double>(i) + 1)*(static_cast<double>(i) + 1));
*/

import std;

#include <cmath>

int main()
{
  unsigned long long n {};
  std::cout << "Enter the number of array elements: ";
  std::cin >> n;
  auto* values{ new double[n] };
  for (unsigned long long i {}; i < n; ++i)
    *(values+i) = 1.0 / ((i + 1)*(i + 1));

  double sum {};
  for (unsigned i {}; i < n; ++i)
    sum += values[i];

  std::println("The result is {}", std::sqrt(6.0 * sum));
  
  delete[] values;   // Don't forget to free the memory!
}