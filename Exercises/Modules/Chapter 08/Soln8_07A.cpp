// Exercise 8-7 Computing Fibonacci numbers iteratively. 
// On most systems (it depends on sizeof(unsigned long long)),
// you can correctly compute up to 93 Fibonacci numbers with this program.
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
	// Initialise fib(i) and fib(i+1) for the first iteration of the loop where i == 0
	unsigned long long fib_i{0};         // fib(i)   = fib(0) = 0
	unsigned long long fib_i_1{1};       // fib(i+1) = fib(1) = 1
	
	for (unsigned int i{}; i < n; ++i)
	{
		auto fib_i_2{ fib_i + fib_i_1 }; // fib(i+2) = fib(i) + fib(i+1)
		
		// Get ready for the next iteration (mind the order!):
		fib_i   = fib_i_1;
		fib_i_1 = fib_i_2;
	}
	
	// At the end of the loop, i was equal to n, so fib(i) == fib(n), which is what we needed
	return fib_i;
}