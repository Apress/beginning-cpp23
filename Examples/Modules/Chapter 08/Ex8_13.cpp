// Returning a pointer
import std;

void print_data(const double data[], std::size_t count = 1, 
               const std::string& title = "Data Values",
               unsigned width = 10, unsigned perLine = 5);
const double* largest(const double data[], std::size_t count);
const double* smallest(const double data[], std::size_t count);
double* shift_range(double data[], std::size_t count, double delta);
double* scale_range(double data[], std::size_t count, double divisor);
double* normalize_range(double data[], std::size_t count);

int main()
{
  double samples[] {
                     11.0,  23.0,  13.0,  4.0,
                     57.0,  36.0, 317.0, 88.0,
                      9.0, 100.0, 121.0, 12.0
                   };

  const auto count{std::size(samples)};                // Number of samples
  print_data(samples, count, "Original Values");       // Output original values
  normalize_range(samples, count);                     // Normalize the values
  print_data(samples, count, "Normalized Values", 12); // Output normalized values
}

// Prints an array of double values
void print_data(const double data[], std::size_t count, 
               const std::string& title, unsigned width, unsigned perLine)
{
  std::println("{}", title);      // Display the title

  // Print the data values
  for (std::size_t i {}; i < count; ++i)
  {
    // Use dynamic field width and precision (see Chapter 7)
    std::print("{:{}.{}g}", data[i], width, width / 2); 
    if ((i + 1) % perLine == 0)   // Newline after perLine values
      std::println("");
  }
  std::println("");
}

const double* smallest(const double data[], std::size_t count)
{
  if (count == 0) return nullptr;   // There is no smallest in an empty array

  std::size_t index_min {};
  for (std::size_t i {1}; i < count; ++i)
    if (data[index_min] > data[i])
      index_min = i;

  return &data[index_min];
}

double* shift_range(double data[], std::size_t count, double delta)
{
  for (std::size_t i {}; i < count; ++i)
    data[i] += delta;
  return data;
}

const double* largest(const double data[], std::size_t count)
{
  if (count == 0) return nullptr;  // There is no largest in an empty array

  std::size_t index_max {};
  for (std::size_t i {1}; i < count; ++i)
    if (data[index_max] < data[i])
      index_max = i;

  return &data[index_max];
}

double* scale_range(double data[], std::size_t count, double divisor)
{
  if (divisor == 0) return data;   // Do nothing for a zero divisor

  for (std::size_t i{}; i < count; ++i)
    data[i] /= divisor;
  return data;
}

double* normalize_range(double data[], std::size_t count)
{
  shift_range(data, count, -(*smallest(data, count)));
  return scale_range(data, count, *largest(data, count));
}
