// Exercise 8-7 Computing Fibinacci numbers recursively. 
// Main thing to realise is that the recursion needs two base cases.
// Key is also to use unsigned values (function would fail for negative numbers)
// and not to forget about zero either (using n == 1 and n == 2 as base cases 
// would mean trouble if n == 0 is passed)
import <iostream>;
import <print>;

unsigned long long fib(size_t n);

int main()
{
  size_t num{};
  std::print("Good day, master. How many Fibonacci numbers shall I compute today? ");
  std::cin >> num;
  
  for (size_t i{1}; i <= num; ++i)
     std::println("fib({}) = {}", i, fib(i));
}

unsigned long long fib(size_t n)
{
  switch (n)
  {
    case 0:  return 0;
    case 1:  return 1;
    default: return fib(n-2) + fib(n-1);
  }
}