// Sorting an array in ascending sequence using an indefinite while loop
import std;

int main()
{
  const std::size_t size {1000}; // Array size
  double data[size] {};          // Stores data to be sorted
  std::size_t count {};          // Number of values in array

  while (true)
  {
    double input {};            // Temporary store for a value
    std::print("Enter a non-zero value, or 0 to end: ");
    std::cin >> input;
    if (input == 0)
      break;

    data[count] = input;

    if (++count == size)
    {
      std::println("Sorry, I can only store {} values.", size);
      break;
    }
  }

  if (count == 0)
  {
    std::println("Nothing to sort...");
    return 0;
  }

  std::println("Starting sort...");

  while (true)
  {
    bool swapped{ false };    // Becomes true when not all values are in order
    for (std::size_t i {}; i < count - 1; ++i)
    {
      if (data[i] > data[i + 1])    // Out of order so swap them
      {
        const auto temp{ data[i] };
        data[i] = data[i+1];
        data[i + 1] = temp;
        swapped = true;
      }
    }

    if (!swapped)    // If there were no swaps
      break;         // ...all values are in order...
  }                  // ...otherwise, go round again.

  std::println("Your data in ascending sequence:");
  const unsigned perline {10};  // Number output per line
  unsigned n {};                // Number on current line
  for (std::size_t i {}; i < count; ++i)
  {
    std::print("{:8.1f}", data[i]);
    if (++n == perline)        // When perline have been written...
    {
      std::println("");        // Start a new line and...
      n = 0;                   // ...reset count on this line
    }
  }
  std::println("");
}
