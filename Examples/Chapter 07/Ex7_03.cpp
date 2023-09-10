// Comparing strings
import std;

int main()
{
  std::vector<std::string> names;     // Vector of names
  std::string input_name;             // Stores a name

  for (;;)                            // Indefinite loop (stopped using break)
  {
    std::print("Enter a name followed by Enter (leave blank to stop): ");
    std::getline(std::cin, input_name);  // Read a name and...
    if (input_name.empty()) break;       // ...if it's not empty...
    names.push_back(input_name);         // ...add it to the vector
  }

  // Sort the names in ascending sequence
  bool sorted {};                      
  do
  {
    sorted = true;                // remains true when names are sorted
    for (std::size_t i {1}; i < names.size(); ++i)
    {
      if (names[i-1] > names[i])
      { // Out of order - so swap names
        names[i].swap(names[i-1]);
        sorted = false;
      }
    }
  } while (!sorted);

  // Find the length of the longest name
  std::size_t max_length{};
  for (const auto& name : names)
    if (max_length < name.length())
      max_length = name.length();

  // Output the sorted names 5 to a line
  const std::size_t field_width{ max_length + 2 };
  std::size_t count {};

  std::println("In ascending sequence the names you entered are:");
  for (const auto& name : names)
  {
    std::print("{:>{}}", name, field_width); // Right-align + dynamic width
    if (!(++count % 5)) std::println("");
  }

  std::println("");
}
