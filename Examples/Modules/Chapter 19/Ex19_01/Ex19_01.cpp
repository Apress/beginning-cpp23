// Exercising pointers to functions
import std;

long sum(long a, long b);           // Function prototype
long product(long a, long b);       // Function prototype

int main()
{
  long(*fun_ptr)(long, long) {};    // Pointer to function

  fun_ptr = product;
  std::println("3 * 5 = {}", fun_ptr(3, 5));  // Call product() thru fun_ptr

  fun_ptr = sum;       // Reassign pointer and call sum() thru fun_ptr twice
  std::println("3 * (4+5) + 6 = {}", fun_ptr(product(3, fun_ptr(4, 5)), 6));
}

// Function to multiply two values
long product(long a, long b) { return a * b; }

// Function to add two values
long sum(long a, long b) { return a + b; }
