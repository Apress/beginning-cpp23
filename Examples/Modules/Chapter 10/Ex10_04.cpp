// constexpr if
import std;

template<typename T> 
decltype(auto) larger(const T& a, const T& b)
{
  if constexpr (std::is_pointer_v<T>)
    return *a > *b ? a : b;   // Only compiled if T is a pointer type
  else
    return a > b ? a : b;     // Only compiled if T is not a pointer type
}

int main()
{
  const int big_int {17011983}, small_int {10};
  std::println("Larger of {} and {} is {}", 
               big_int, small_int, larger(big_int, small_int));
  std::println("Larger of {} and {} is {}",
               big_int, small_int, *larger(&big_int, &small_int));
}
