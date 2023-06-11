// Exercise 9.3. Using vocabulary types 
import std;

// Note: while we didn't do so in this solution (go ahead if you want),
// you could also replace the optional parameters 
// of show_data() with parameters of form std::optional<...> = {}.
// In the function definition you could then use expressions such as 
// title.value_or("Data Values"), or perLine.value_or(5).
// One advantage of that approach
// (beyond making it more explicit that the parameters are optional)
// would be that you can then change the default argument values 
// without recompiling the function call sites.

void show_data(std::span<const double> data, 
               std::string_view title = "Data Values",
               std::size_t width = 10, std::size_t perLine = 5);
std::optional<double> largest(std::span<const double> data);
std::optional<double> smallest(std::span<const double> data);
std::span<double> shift_range(std::span<double> data, double delta);
std::span<double> scale_range(std::span<double> data, double divisor);
std::span<double> normalize_range(std::span<double> data);

int main()
{
  double samples[] {
                     11.0,  23.0,  13.0,  4.0,
                     57.0,  36.0, 317.0, 88.0,
                      9.0, 100.0, 121.0, 12.0
                   };

  show_data(samples, "Original Values");        // Output original values
  normalize_range(samples);                     // Normalize the values
  show_data(samples, "Normalized Values", 12);  // Output normalized values
}

// Outputs a sequence of double values
void show_data(std::span<const double> data,
               std::string_view title, std::size_t width, std::size_t perLine)
{
  std::println("{}", title);  // Print the title

  // Output the data values
  for (std::size_t i {}; i < data.size(); ++i)
  {
    // Print a data item (uses a dynamic field width: see Chapter 7)
    std::print("{:{}.6g}", data[i], width); 
    if ((i + 1) % perLine == 0)     // Newline after perLine values
      std::println("");
  }
  std::println("");
}

std::optional<double> smallest(std::span<const double> data)
{
  if (data.empty()) return {};     // There is no smallest in an empty sequence

  std::size_t index_min {};
  for (std::size_t i {1}; i < data.size(); ++i)
    if (data[index_min] > data[i])
      index_min = i;

  return data[index_min];
}

std::span<double> shift_range(std::span<double> data, double delta)
{
  for (std::size_t i {}; i < data.size(); ++i)
    data[i] += delta;
  return data;
}

std::optional<double> largest(std::span<const double> data)
{
  if (data.empty()) return {};    // There is no largest in an empty sequence

  std::size_t index_max {};
  for (std::size_t i {1}; i < data.size(); ++i)
    if (data[index_max] < data[i])
      index_max = i;

  return data[index_max];
}

std::span<double> scale_range(std::span<double> data, double divisor)
{
  if (!divisor) return data;     // Do nothing for a zero divisor

  for (std::size_t i{}; i < data.size(); ++i)
    data[i] /= divisor;
  return data;
}

std::span<double> normalize_range(std::span<double> data)
{
  shift_range(data, -(*smallest(data)));
  return scale_range(data, *largest(data));
}
