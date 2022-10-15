// Exercise 6-2. Traversing arrays using pointer arithmetics
// An exercise to further deepen your understanding of the relation 
// between pointers, pointer arithmetic, and arrays.

import std;

int main()
{
  const int n {50};
  int odds[n];
  for (int i {}; i < n; ++i)
    odds[i] = i * 2 + 1;

  const int perline {10};
  std::println("The {} first odd numbers are:", n);
  
  int* traversal_pointer{ odds };
  for (int i {}; i < n; ++i)
  {
    std::print("{:5}", *traversal_pointer++);
    if ((i + 1) % perline == 0)   // Uses the loop counter to decide when a newline is required
      std::println("");
  }

  std::println("\nIn reverse order these numbers are:");
  for (int i {}; i < n; ++i)      // No need to reverse the manipulation of the loop counter now
  {
    std::print("{:5}", *(--traversal_pointer)); // Use the pre-decrement operator to make sure the pointer is decremented
    if ((i + 1) % perline == 0)                 // before it is dereferenced (at the start of this loop, 
      std::println("");                         // the pointer points one passed the last element of the odds array)
  }
}