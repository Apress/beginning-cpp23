// Exercise 6-6. Storing a dynamically allocated vector in a smart pointer

import std;

int main()
{
  unsigned long long n {};
  std::print("Enter the number of vector elements: ");
  std::cin >> n;
  auto values{ std::make_unique<std::vector<double>>(n) };

  for (unsigned long long i {}; i < n; ++i) // See Soln6_03 for the use of unsigned long long
    (*values)[i] = 1.0 / ((i + 1)*(i + 1));
  
  double sum {};
  for (auto value : *values)
    sum += value;

  std::println("Result is {}", std::sqrt(6.0*sum));
  
  // No need to deallocate the memory yourself anymore: the smart pointer takes care of that for you!
}