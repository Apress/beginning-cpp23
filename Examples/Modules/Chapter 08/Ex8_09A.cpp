// Passing an array to a function - pass by reference
// Note: with main() as defined in this file, this program will not compile...
import <print>;

double average10(const double (&)[10]);        // Function prototype

int main()
{
  // Use 10 values to make example compile...
 // double values[] { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
  double values[] { 1.0, 2.0, 3.0 };           // Only three values!!!
  std::println("Average = {}", average10(values));
}

// Function to compute an average
double average10(const double (&array)[10])   /* Only arrays of length 10 can be passed! */
{
  double sum {};                       // Accumulate total in here
  for (std::size_t i {}; i < 10; ++i)
    sum += array[i];                   // Sum array elements
  return sum / 10;                     // Return average
}
