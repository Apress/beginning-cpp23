// Exercise 21-3 
import std;

// By default, take the N / 2'th element
template <typename T, std::size_t N>
auto& medianOfSorted(std::span<T, N> span)
{
  static_assert(N != 0, "The median of an empty span is not defined");
  return span[N / 2];
}

template <typename T, std::size_t N> requires (N % 2 == 0)
auto medianOfSorted(std::span<T, N> span)
{
  static_assert(N != 0, "The median of an empty span is not defined");
  return (span[N / 2 - 1] + span[N / 2]) / 2;
}

int main()
{
  std::array values_odd{ 1, 2, 3, 4, 5, 6, 7 };
  std::println("{}", medianOfSorted(std::span{values_odd}));

  std::array values_even{ 1., 2., 3., 4., 5., 6. };
  std::println("{}", medianOfSorted(std::span{ values_even }));
}