// Creating a function template for my_clamp(), 
// a template that produces functions to clamp values to a given interval.
// Different variations are possible, but we opted for the same as in the Standard Library:
// namely one where all three arguments are of the same type, and passed by reference-to-const.
import std;

template<typename T> 
const T& my_clamp(const T& value, const T& low, const T& high);    // Function template prototype

int main() 
{
  std::println("2.0 clamped to interval [1.5, 2.5] is {}", my_clamp(2.0, 1.5, 2.5));
  std::println("5.0 clamped to interval [1.5, 2.5] is {}", my_clamp(5.0, 1.5, 2.5));

  int big_int {17011983}, small_int {10}, negative_int {-123};
  std::println("{} clamped to the interval [{},{}] is {}", 
          negative_int, small_int, big_int, my_clamp(negative_int, small_int, big_int));

  // And now for a less useful example...
  std::string a_string {"A"}, z_string {"Z"};
  std::string shakespeare{"It is not in the stars to hold our destiny but in ourselves"};
  std::println("William Shakespeare's quote clamped to [A-Z] is: {}", my_clamp(shakespeare, a_string, z_string));
}

// Template for functions to clamp a value to a closed interval
template<typename T> 
const T& my_clamp(const T& value, const T& low, const T& high)
{
  if (value < low) return low;
  else if (value < high) return value;
  else return high;
}
