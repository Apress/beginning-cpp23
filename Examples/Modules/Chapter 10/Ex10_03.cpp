// Using return type deduction with templates
import std;

// Template for functions to return the larger of two values
// Supports implicit conversion of differently-typed arguments
template <typename T1, typename T2>
auto larger(const T1& a, const T2& b)
{
  return a > b ? a : b;
}

int main()
{
  const int small_int {10};
  std::println("Larger of {} and 9.6 is {}", 
               small_int, larger(small_int, 9.6));  // deduced return type: double
  
  const std::string a_string {"A"};
  std::println(R"(Larger of "{}" and "Z" is "{}")",
               a_string , larger(a_string, "Z"));   // deduced return type: std::string
}

