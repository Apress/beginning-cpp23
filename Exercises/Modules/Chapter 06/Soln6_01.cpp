// Exercise 6-1. Storing odd numbers in an array and accessing them using pointer notation

/* Note that the use of pointer notation is just for the sake of the exercise,           *
 * to help you understand the intimate relation between pointers and array names.        *
 * In real code, you'd normally just use array notation, because it is that much easier. */

import std;

int main()
{
  const int n {50};
  int odds[n];
  for (int i {}; i < n; ++i)
    odds[i] = i * 2 + 1;

  const int perline {10};
  std::println("The {} first odd numbers are:", n);
  for (int i {}; i < n; ++i)
  {
    std::print("{:5}", *(odds + i));
    if ((i + 1) % perline == 0)            // Uses the loop counter to decide when a newline is required
      std::println("");
  }

  std::println("\nIn reverse order these numbers are:");
  for (int i {n - 1}; i >= 0; --i)         // Caution: this won't work with a loop counter of type std::size_t
  {                                        // because std::size_t cannot be negative
    std::print("{:5}", *(odds + i));
    if (i % perline == 0)
      std::println("");
  }
}