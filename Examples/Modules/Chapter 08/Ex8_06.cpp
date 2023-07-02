// Passing a two-dimensional array to a function
import std;

double yield(const double values[][4], std::size_t n);

int main()
{
  double beans[3][4] {  { 1.0,   2.0,   3.0,   4.0},
                        { 5.0,   6.0,   7.0,   8.0},
                        { 9.0,  10.0,  11.0,  12.0}  };

  std::println("Yield = {}", yield(beans, std::size(beans)));
}

// Function to compute total yield
double yield(const double array[][4], std::size_t size)
{
  double sum  {};
  for (std::size_t i {}; i < size; ++i)   // Loop through rows
  {
    for (std::size_t j {}; j < std::size(array[i]); ++j) // Loop through elements in a row
    {
      sum += array[i][j];
    }
  }
  return sum;
}
