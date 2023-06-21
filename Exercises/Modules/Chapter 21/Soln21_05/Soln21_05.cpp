// Exercise 21-5  Generalizing medianOfSorted()
import std;

/*
  Key point here is that underlying, range-based algorithms still very much work with iterators.
  Most requirements use Standard Library concepts in the std::ranges namespace,
  and the function implementations use Standard Library functions in that same namespace.
 */

/* To take an average, a type needs to support at least at least addition, and division by an integer. 
   The other operations are added to obtain a more cohesive set of operations.
*/
template <typename T>
concept Averagable = requires (const T x, const T y, T z, const int i)
{
  { x + y }  -> std::same_as<T>;
  { x - y }  -> std::same_as<T>;
  { z += y } -> std::same_as<T&>;
  { z -= y } -> std::same_as<T&>;
  { x / i }  -> std::same_as<T>;
  { x * i }  -> std::same_as<T>;
  { z /= i } -> std::same_as<T&>;
  { z *= i } -> std::same_as<T&>;
};

// By default, take the N/2'th element (generally returns a reference then)
template <std::ranges::sized_range Range>   // Requires being able to determine the range's size using std::ranges::size()
  requires std::ranges::input_range<Range>  // Requires being able to dereference an iterator over the range.
decltype(auto) medianOfSorted(Range&& range)
{
  auto iter{ std::ranges::begin(range) };   // Supported for every range
  std::ranges::advance(iter, std::ranges::size(range) / 2);  // Advances in constant time for random-access ranges, linearly otherwise.
  return *iter;                             // Only possible with input iterators...
}

// When we can take an average (and have an appropriate range), 
// check the size to decide whether we need to do so...
template <std::ranges::sized_range Range> 
  requires std::ranges::forward_range<Range>  // More strict than before: we need the multi-pass guarantee
        && Averagable<std::ranges::range_value_t<Range>>
auto medianOfSorted(Range&& range)
{
  const auto N{ std::ranges::size(range) };
  auto iter{ std::ranges::begin(range) };
  if (N % 2 == 0)
  {
    std::ranges::advance(iter, N / 2 - 1);
    const auto& value1{ *iter };      // Reference remains valid because iter is a forward iterator!
    std::ranges::advance(iter, 1);
    return (value1 + *iter) / 2;
  }
  else
  {
    std::ranges::advance(iter, N / 2);
    return *iter;
  }
}

int main()
{
  std::array values_odd{ 1, 2, 3, 4, 5, 6, 7 };
  std::println("{}", medianOfSorted(values_odd));

  std::array values_even{ 1., 2., 3., 4., 5., 6. };
  std::println("{}", medianOfSorted(values_even));

  std::string strings_odd[] { "1", "2", "3", "4", "5" };
  std::println("{}", medianOfSorted(strings_odd));

  std::string strings_even[] { "1", "2", "3", "4", "5", "6" };
  std::println("{}", medianOfSorted(std::span{ strings_even }));

  std::vector dynamically_sized{ 1.f, 2.f, 3.f, 4.f };
  std::println("{}", medianOfSorted(dynamically_sized));

  std::list non_random_access{ 4.f, 3.f, 2.f, 1.f, 0.f };
  std::println("{}", medianOfSorted(non_random_access));

  std::forward_list non_sized_ranged{ 123, 456, 789 };
  //std::println("{}", medianOfSorted(non_sized_ranged)); /* Error: not sized! */
}