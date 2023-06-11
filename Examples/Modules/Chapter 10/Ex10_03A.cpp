// Using return type deduction with templates (decltype(auto) instead of auto)
import std;

// Template for functions to return the larger of two values
// Supports implicit conversion of differently-typed arguments
template <typename T1, typename T2>
decltype(auto) larger(const T1& a, const T2& b)
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

  const std::vector v1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  const std::vector v2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 11 };
  std::println("The larger of our two vectors ends with {}", larger(v1, v2).back());
}

