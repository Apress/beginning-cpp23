// Constant expressions 

import std;

constexpr int sqrt(int x)
{
#ifdef __cpp_if_consteval  // Conditional compilation depending on whether consteval if statements are supported (see Appendix A)
  if consteval
#else
  if (std::is_constant_evaluated())
#endif
  {
    int result{};
    while (result * result <= x) ++result;
    return result - 1;
  }
  else
  {
    return static_cast<int>(std::sqrt(x)); // Only constexpr as of C++26
  }
}

int main()
{
  constexpr int a = sqrt(100); // Uses slow version
  int b = sqrt(1'000'000'000); // Uses fast version

  std::println("a: {} - b: {}", a, b);
}
