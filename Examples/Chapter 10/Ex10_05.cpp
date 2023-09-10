// Defining templates for functions that accept fixed-size arrays
import std;

template <typename T, std::size_t N>
T average(const T(&array)[N]);

int main()
{
  double doubles[2] { 1.0, 2.0 };
  std::println("{}", average(doubles));

  double moreDoubles[] { 1.0, 2.0, 3.0, 4.0 };
  std::println("{}", average(moreDoubles));

 // double* pointer{ doubles };
 // std::println("{}", average(pointer));      /* will not compile */

  std::println("{}", average({ 1.0, 2.0, 3.0, 4.0 }));

  int ints[] { 1, 2, 3, 4 };
  std::println("{}", average(ints));
}

template <typename T, std::size_t N>
T average(const T(&array)[N])
{
  T sum{};                         // Accumulate total in here
  for (std::size_t i{}; i < N; ++i)
    sum += array[i];               // Sum array elements
  return sum / N;                  // Return average
}