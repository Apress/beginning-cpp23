// Defining and using a move assignment operator
import array;
import std;

// Construct an Array<> of a given size, filled with some arbitrary string data
Array<std::string> buildStringArray(const size_t size)
{
  Array<std::string> result{ size };
  for (std::size_t i {}; i < size; ++i)
    result[i] = "You should learn from your competitor, but never copy. Copy and you die.";
  return result;
}

int main()
{
  Array<std::string> strings { 123 };
  strings = buildStringArray(1'000);           // Assign an rvalue to strings

  Array<std::string> more_strings{ 2'000 };
  strings = more_strings;                      // Assign an lvalue to strings
}
