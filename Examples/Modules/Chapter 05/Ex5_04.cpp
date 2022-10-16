// Multiple initializations in a loop expression
import std;

int main()
{
  unsigned int limit {};
  std::print("This program calculates n! and the sum of the integers up to n ");
  std::print("for values 1 to limit.\nWhat upper limit for n would you like? ");
  std::cin >> limit;

  // The format string for all rows of the table
  constexpr auto table_format = "{:>8} {:>8} {:>20}";
  
  // Output column headings
  std::println(table_format, "integer", "sum", "factorial"); 

  for (unsigned long long n {1}, sum {}, factorial {1}; n <= limit; ++n)
  {
    sum += n;           // Accumulate sum to current n
    factorial *= n;     // Calculate n! for current n
    std::println(table_format, n, sum, factorial);
  }
}
