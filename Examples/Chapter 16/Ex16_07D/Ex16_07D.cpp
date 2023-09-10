// Avoid resource leaks due to exceptions using std::unique_ptr<>
// Note: this example is given but not named in the text.
// Instead of a custom RAII class DoubleArrayRAII, it uses std::vector<>.
// Unlike the former, the latter can of course be returned from computeValues() as well.
import std;
import troubles;

double computeValue(std::size_t x);      // A function to compute a single value
std::vector<double> computeValues(std::size_t howMany); // A function to compute an array of values

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

std::vector<double> computeValues(std::size_t howMany)
{
  std::vector<double> values;
  for (std::size_t i{}; i < howMany; ++i)
    values.push_back(computeValue(i));
  return values;
}

double computeValue(std::size_t x)
{
  if (x < 100)
    return std::sqrt(x);   // Return the square root of the input argument
  else
    throw Trouble{ "The trouble with trouble is, it starts out as fun!" };
}

