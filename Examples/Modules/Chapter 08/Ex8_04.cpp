// Modifying the value of a caller variable
import std;

double changeIt(double* pointer_to_it);    // Function prototype

int main()
{
  double it {5.0};
  double result {changeIt(&it)};      // Now we pass the address

  std::println("After function execution, it = {}", it);
  std::println("Result returned is {}", result);
}

// Function to modify an argument and return it
double changeIt(double* pit)
{
  *pit += 10.0;             // This modifies the original double
  std::println("Within function, *pit = {}", *pit);
  return *pit;
}
