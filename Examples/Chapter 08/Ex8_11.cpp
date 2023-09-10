// Using multiple default argument values
import std;

// The function prototype including default arguments
void print_data(const int data[], std::size_t count = 1,  
                const std::string& title = "Data Values",
                unsigned width = 10, unsigned perLine = 5);
int main()
{
  int samples[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

  int dataItem {-99};
  print_data(&dataItem);

  dataItem = 13;
  print_data(&dataItem, 1, "Unlucky for some!");

  print_data(samples, std::size(samples));
  print_data(samples, std::size(samples), "Samples");
  print_data(samples, std::size(samples), "Samples", 6);
  print_data(samples, std::size(samples), "Samples", 8, 4);
}

void print_data(const int data[], std::size_t count, const std::string& title, 
                unsigned width, unsigned perLine)
{
  std::println("{}", title);    // Display the title

  // Output the data values
  for (std::size_t i {}; i < count; ++i)
  {
    std::print("{:{}}", data[i], width); // Display a data item
    if ((i+1) % perLine == 0)            // Newline after perLine values
      std::println("");
  }
  std::println("");
}
