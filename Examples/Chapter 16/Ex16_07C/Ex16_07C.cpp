// Avoid resource leaks due to exceptions using std::unique_ptr<>
// Note: this example is given but not named in the text.
// Instead of a custom RAII class DoubleArrayRAII, it uses std::unique_ptr<>.
// Unlike the former, the latter can be returned from computeValues() as well.
import std;
import troubles;

double computeValue(std::size_t x);      // A function to compute a single value
std::unique_ptr<double[]> computeValues(std::size_t howMany); // A function to compute an array of values

int main()
{
  try
  {
    auto values{ computeValues(10'000) }; // Cannot leak either: resource is managed by RAII object!
  }
  catch (const Trouble&)
  {
    std::println("No worries: I've caught it!");
  }
}

std::unique_ptr<double[]> computeValues(std::size_t howMany)
{
  auto values{ std::make_unique<double[]>(howMany) };
  for (std::size_t i{}; i < howMany; ++i)
    values[i] = computeValue(i);
  return values;
}

double computeValue(std::size_t x)
{
  if (x < 100)
    return std::sqrt(x);   // Return the square root of the input argument
  else
    throw Trouble{ "The trouble with trouble is, it starts out as fun!" };
}

