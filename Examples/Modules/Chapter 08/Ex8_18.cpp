// Constant expressions 

import std;

// Uncomment constexpr to make the definitions of a8 and p compile
/*constexpr*/ std::size_t power(std::size_t x, unsigned n)
{
  return n == 0 ? 1 : x * power(x, n - 1);
}

int main()
{
  std::array<int, 1> a1;                // Ok: literals are constant expressions
  
  const std::size_t integer_constant{ 2 };
  std::array<int, integer_constant> a2; // Ok: integer constants are constant expressions
  
  enum class Size { ONE = 1, TWO = integer_constant, THREE }; // Ok: integer constant
  std::array<int, static_cast<std::size_t>(Size::THREE)> a3;  // Ok: enumerator
  
  std::array<int, 2 * integer_constant> a4;  // Ok: constant expression operands
  
  std::size_t variable{ 5 };
  std::array<int, variable> a5; /* Error: non-const integers are not constant expressions */
  
  // Uncomment constexpr to make the definition of a6 compile
  /*constexpr*/ const double floating_constant{ 6 };
  /* Error: const non-integers are not constant expressions */
  std::array<int, static_cast<std::size_t>(floating_constant)> a6;
  
  std::array<int, std::abs(-7)> a7;     // Ok to use std::abs() (as of C++23)
  
  std::array<int, power(2, 3)> a8;   /* Error: power() may not be used in constant expression */
  
  constexpr std::size_t p{ power(3, 2) }; /* Error: cannot use power() in constant expression */
  
  int user_input;
  std::cin >> user_input;
  std::println("Runtime power: {}", power(user_input, 2));
}
