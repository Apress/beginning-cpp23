// Exercising a single, exception safe overload of push_back() 
// Remove the noexcept specifiers from Array<> to observe
// that copying is then used instead of moving
// (moving would be unsafe if an exception occurs).
import array;
import std;

// Construct an Array<> of a given size, filled with some arbitrary string data
Array<std::string> buildStringArray(const std::size_t size)
{
  Array<std::string> result{ size };
  for (std::size_t i {}; i < size; ++i)
    result[i] = "You should learn from your competitor, but never copy. Copy and you die.";
  return result;
}

int main()
{
  Array<Array<std::string>> array_of_arrays;

  Array<std::string> array{ buildStringArray(1'000) };
  array_of_arrays.push_back(array);              // Push an lvalue

  array.push_back("One more for good measure");
  std::println("");

  array_of_arrays.push_back(std::move(array));   // Push an rvalue
}