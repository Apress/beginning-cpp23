// Generating multiplication tables using nested loops
import std;

int main()
{
  int table {};             // Table size
  const int table_min {2};  // Minimum table size - at least up to the 2-times
  const int table_max {12}; // Maximum table size
  char reply {};            // Response to prompt

  do
  {
    std::print("What size table would you like ({} to {})? ", table_min, table_max);
    std::cin >> table;          // Get the table size
    
    // Make sure table size is within the limits
    if (table < table_min || table > table_max)
    {
      std::println("Invalid table size entered. Program terminated.");
      return 1;
    }
    std::println("");

    // Create the top line of the table
    std::print("{:>6}", '|');
    for (int i {1}; i <= table; ++i)
    {
      std::print(" {:3} |", i);
    }
    std::println("");

    // Create the separator row
    for (int i {}; i <= table; ++i)
    {
      std::print("------");
    }
    std::println("");

    for (int i {1}; i <= table; ++i)
    {    // Iterate over rows
      std::print(" {:3} |", i);      // Start the row

      // Output the values in a row
      for (int j {1}; j <= table; ++j)
      {
        std::print(" {:3} |", i*j); // For each column
      }
      std::println("");             // End the row
    }

    // Check if another table is required
    std::print("\nDo you want another table (y or n)? ");
    std::cin >> reply;

  } while (std::tolower(reply) == 'y');
}
