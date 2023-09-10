// Defining a function template for adding numbers, 
// and an overload that works for pointer types.
// Extra: also make plus() work with string literals...
import std;

// As always, different variations are possible,
// but since the exercise asks you to allow "potentially different types",
// it makes most sense to use two different template type parameters 
// (be it explicitly using template <typename T1, typename T2>, 
// or implicitly through abbreviated function template syntax as we did).

auto plus(const auto& a, const auto& b)
{
  return a + b;
}

// Overload with another template for pointer types
auto plus(const auto* a, const auto* b)
{
  return *a + *b;
}

// Overload with a plain function for string literals / C-style strings.
// The return type cannot be const char*, since we need to create a new string.
// Function template specialization could therefore not be used, even if you wanted to...
std::string plus(const char* a, const char* b)
{
  return std::string{ a } + b;
}

int main()
{
    int n{ plus(3, 4) };
    std::println("plus(3, 4) returns {}", n);
    
    double d{ plus(3.2, 4.2) };
    std::println("plus(3.2, 4.2) returns {}", d);
    
    std::string s1{ "aaa" };
    std::string s2{ "bbb" };
    auto s3{ plus(s1, s2) };
    std::println("With s1 as {} and s2 as {}, plus(s1, s2) returns {}", s1, s2, s3);

    // The extra part:
    std::println("plus(\"he\", \"llo\") returns {}", plus("he", "llo"));

    // Note: std::string + literal also works thanks to non-member + operators for std::string...
    std::println("plus(s1, \"llo\") returns {}", plus(s1, "llo"));
}