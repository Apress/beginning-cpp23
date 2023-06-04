// Exercise 6-5. Managing a dynamic array using a smart pointer
// You can no longer use pointer notation now!
// (You could, technically, call get() first and then use pointer notation,
// though why make the syntax even more convoluted: just use array notation!)

import std;

int main()
{
  unsigned long long n {};
  std::print("Enter the number of array elements: ");
  std::cin >> n;
  auto values{ std::make_unique<double[]>(n) };
  for (unsigned long long i {}; i < n; ++i) // See Soln6_03 for the use of unsigned long long
    values[i] = 1.0 / ((i + 1)*(i + 1));

  double sum {};
  for (unsigned long long i {}; i < n; ++i)
    sum += values[i];

  std::println("The result is {}", std::sqrt(6.0 * sum));
  
  // No need to deallocate the memory yourself anymore: the smart pointer takes care of that for you!
}