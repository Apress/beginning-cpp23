// Using a function template
import std;

template<typename T> T larger(T a, T b);    // Function template prototype

int main()
{
  std::println("Larger of 1.5 and 2.5 is {}", larger(1.5, 2.5));
  std::println("Larger of 3.5 and 4.5 is {}", larger(3.5, 4.5));

  const int big_int {17011983}, small_int {10};
  std::println("Larger of {} and {} is {}", 
               big_int, small_int, larger(big_int, small_int));

  const std::string a_string {"A"}, z_string {"Z"};
  std::println(R"(Larger of "{}" and "{}" is "{}")", 
               a_string, z_string, larger(a_string, z_string));
}


// Template for functions to return the larger of two values
template <typename T>
T larger(T a, T b)
{
    return a > b ? a : b;
}

