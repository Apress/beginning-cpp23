// Constant expressions 

import std;

// Logs an error to a log file
constexpr void logError(const std::string& error);
// Compute the (floor of) the square root of an integer
constexpr int sqrt(int x)
{
  if (x < 0)
  {
    logError("Oh no, this can't be real...");
    return -1;
  }
  int result{ 1 };
  while (result * result <= x) ++result;
  return result - 1;
}

constexpr void logError(const std::string& error)
{
#ifdef __cpp_if_consteval  // Conditional compilation depending on whether consteval if statements are supported (see Appendix A)
  if !consteval
#else
  if (!std::is_constant_evaluated())
#endif
  {
    // Stream to the standard error stream std::cerr
    // (not really covered in the book, but for sure not constexpr)
    std::cerr << error << std::endl;
  }
}


int main()
{
	constexpr int a = sqrt(25); // OK
	constexpr int b = sqrt(-1); // OK now: logError() simply does nothing
    int c = sqrt(-1); // OK: logError() still outputs error message at runtime

    std::println("a: {} - b: {} - c: {}", a, b, c);
}
