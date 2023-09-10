// Exercise 8-7 Computing Fibonacci numbers recursively. 
// Main thing to realize is that the recursion needs two base cases.
// Key is also to use unsigned values (function would fail for negative numbers)
// and not to forget about zero either (using n == 1 and n == 2 as base cases 
// would mean trouble if n == 0 is passed)
import std;

unsigned long long fib(unsigned int n);

int main()
{
  unsigned int num{};
  std::print("Good day, master. How many Fibonacci numbers shall I compute today? ");
  std::cin >> num;
  
  for (unsigned int i{1}; i <= num; ++i)
    std::println("fib({}) = {}", i, fib(i));
}

unsigned long long fib(unsigned int n)
{
  switch (n)
  {
    case 0:  return 0;
    case 1:  return 1;
    default: return fib(n-2) + fib(n-1);
  }
}