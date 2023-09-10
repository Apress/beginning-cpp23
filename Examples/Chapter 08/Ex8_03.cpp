// Failing to modify the original value of a function argument
import std;

double changeIt(double value_to_be_changed);    // Function prototype

int main()  
{
  double it {5.0};
  double result {changeIt(it)};

  std::println("After function execution, it = {}", it);
  std::println("Result returned is {}", result);
}

// Function that attempts to modify an argument and return it
double changeIt(double it)
{
  it += 10.0;                       // This modifies the copy
  std::println("Within function, it = {}", it);
  return it;
}
