// Exercise 9-2 Working with std::string_view<> and std::span<>
import std;

// Note: while we didn't do so in this solution (go ahead if you want),
// you could also replace the optional parameters 
// of both show_data() overloads with parameters of form std::optional<...> = {}.
// In the definitions of these functions you'd then use, say, width.value_or(10).
// One advantage of that approach 
// (beyond making it more explicit that the parameters are optional)
// would be that you can then change the default argument values 
// without recompiling the function call sites.

// The function prototype including defaults for parameters
void show_data(
  std::span<const int> data,
  std::string_view title = "Data Values",
  std::size_t width = 10, std::size_t perLine = 5);

// Extra overload to output a single value.
void show_data(
  int data,
  std::string_view title = "Data Values",
  std::size_t width = 10);

int main()
{
  int samples[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

  int dataItem{ -99 };
  show_data({ &dataItem, 1 });  // Call original function directly

  dataItem = 13;
  show_data(dataItem, "Unlucky for some!"); // Use extra overload

  show_data(samples);
  show_data(samples, "Samples");
  show_data(samples, "Samples", 6);
  show_data(samples, "Samples", 8, 4);
}

void show_data(
  std::span<const int> data, 
  std::string_view title,
  std::size_t width, std::size_t perLine)
{
  std::println("{}", title);    // Print the title

  // Output the data values
  for (std::size_t i{}; i < data.size(); ++i)
  {
    std::print("{:{}}", data[i], width);  // Print a data item
    if ((i + 1) % perLine == 0)           // Newline after perLine values
      std::println("");
  }
  std::println("");
}

void show_data(int data, std::string_view title, std::size_t width)
{
  show_data({ &data, 1 }, title, width);
}
