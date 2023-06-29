// Constant expressions 

import std;

// Logs an error to a log file
void logError(const std::string& error);
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

void logError(const std::string& error)
{
  // Stream to the standard error stream std::cerr
  // (not really covered in the book, but for sure not constexpr)
  std::cerr << error << std::endl;
}


int main()
{
	constexpr int a = sqrt(25); // OK
	constexpr int b = sqrt(-1); /* Error: logError() is not a constexpr function */
    int c = sqrt(-1); // OK: logError() called at runtime

    std::println("a: {} - b: {} - c: {}", a, b, c);
}
