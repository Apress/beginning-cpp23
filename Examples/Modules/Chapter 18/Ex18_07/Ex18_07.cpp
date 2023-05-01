// The effect of not adding noexcept to move members
// Uncomment the noexcept specifiers in the Array<> template source 
// to avoid copying when a std::vector<> grows its dynamic array.
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
  std::vector<Array<std::string>> v;

  v.push_back(buildStringArray(1'000));

  std::println("");

  v.push_back(buildStringArray(2'000));
}