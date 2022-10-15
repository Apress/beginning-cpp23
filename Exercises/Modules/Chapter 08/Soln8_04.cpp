// Exercise 8_4 An overloaded plus() function. 
import std;

int plus(int a, int b);
double plus(double x, double y);
std::string plus(const std::string& s1, const std::string& s2);

int main()
{
  const int n {plus(3, 4)};
  std::println("plus(3, 4) returns {}", n);
  
  const double d {plus(3.2, 4.2)};
  std::println("plus(3.2, 4.2) returns {}", d);
  
  const std::string s {plus("he", "llo")};
  std::println("plus(\"he\", \"llo\") returns {}", s);
  
  const std::string s1 {"aaa"};
  const std::string s2 {"bbb"};
  const std::string s3 {plus(s1, s2)};
  std::println("With s1 as {} and s2 as {} plus(s1, s2) returns {}", s1, s2, s3);

  /*
  const auto d {plus(3, 4.2)};
  This won't compile because there is more than one overloaded plus() function for the arguments.
  The compiler will not choose so there must be a unique match with a function signature.
  */
}

// Adding integer values
int plus(int a, int b)
{
  return a + b;
}

// Adding floating-point values
double plus(double x, double y)
{
  return x + y;
}

// Adding strings
std::string plus(const std::string& s1, const std::string& s2)
{
  return s1 + s2;
}