// Format specifiers for containers
import std;

int main()
{
  std::vector v{ 1, 2, 3, 4 };         // Deduced type: std::vector<int>
  std::println("Default formatting: {}", v);        // [1, 2, 3, 4]
  std::println("No braces: {:n}", v);               // 1, 2, 3, 4
  std::println("Curly braces: {{{:n}}}", v);        // {1, 2, 3, 4}
  std::println("Format range only: {:*^20}", v);    // ****[1, 2, 3, 4]****
  std::println("Format elements only: {::*<3}", v); // [1**, 2**, 3**, 4**]
  std::println("All at once: {:*^20n:03b}", v);     // *001, 010, 011, 100*
}
