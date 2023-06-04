// Exercise 6-3. Storing numbers in a dynamic array
// Btw: notice anything about the result? 
// Try increasing numbers of array elements...

/*
    Caution: the following seemingly reasonable loop leads to an end-result that is infinity
    for larger values of n (say n equal to 100,000):

    for (unsigned i {}; i < n; ++i)
      *(values+i) = 1.0 / ((i + 1)*(i + 1));
    
    Why? We suggest you take a second to think about it... (we certainly had to...)
    You'll probably recall that division-by-zero is the only elementary operation 
    that leads to infinity (if neither of the operands is infinity to begin with, that is).
    And that once infinity enters a computation, the end result generally remains infinity
    (or even degenerates to not-a-number).
    
    The next question is therefore: how can ((i + 1)*(i + 1)) be zero? 
    If the unsigned type is not large enough to represent the result, of course.
    To see why, you could run the following loop

    for (unsigned i{}; i < 100'000; ++i)
      if ((i + 1) * (i + 1) == 0)
        std::println("(i + 1) * (i + 1) == 0 for i == {}", i);

    The output will likely be:

        (i + 1) * (i + 1) == 0 for i == 65535

    65535 is, not coincidentally, equal to 2^16 - 1,
    which means that (65535 + 1) * (65535 + 1) is equal to 2^32, a power of 2 that should ring a bell...
    Note that this also means that for any number larger than 65535,
    the result of (i + 1) * (i + 1) would not be correct anymore.
    In other words: this division-by-zero-leading-to-infinity bug we just described would be somewhat of a blessing,
    as it is far easier to discover than any other wrong results due to integer overflow!

    The solution we went with here is the use of a larger integer type, unsigned long long.
    Another interesting alternative, though, would be to cast the integer to double before performing the computation:

    for (unsigned i {}; i < n; ++i)
      *(values+i) = 1.0 / ((static_cast<double>(i) + 1)*(static_cast<double>(i) + 1));
*/

import std;

int main()
{
  unsigned long long n {};
  std::print("Enter the number of array elements: ");
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