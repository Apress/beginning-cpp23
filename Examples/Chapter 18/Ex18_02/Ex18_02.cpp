// Moving objects into a vector
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
  const std::size_t numArrays{ 10 };  // Fill 10 Arrays with 1,000 strings each
  const std::size_t numStringsPerArray{ 1000 };

  std::vector<Array<std::string>> vectorOfArrays;
  vectorOfArrays.reserve(numArrays);  // Inform the vector<> how many Arrays we'll be adding

  for (std::size_t i {}; i < numArrays; ++i)
  {
     vectorOfArrays.push_back(buildStringArray(numStringsPerArray));
  }
}
