// Finding maximum and minimum values for data types
import std;

int main()
{
  std::println("The range for type short is from {} to {}",
    std::numeric_limits<short>::min(), std::numeric_limits<short>::max());
  std::println("The range for type unsigned int is from {} to {}",
    std::numeric_limits<unsigned int>::min(), std::numeric_limits<unsigned int>::max());
  std::println("The range for type long long is from {} to {}",
    std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
  std::println("The positive range for type float is from {} to {}",
    std::numeric_limits<float>::min(), std::numeric_limits<float>::max());
  std::println("The full range for type float is from {} to {}",
    std::numeric_limits<float>::lowest(), std::numeric_limits<float>::max());
  std::println("The positive range for type double is from {} to {}",
    std::numeric_limits<double>::min(), std::numeric_limits<double>::max());
}
