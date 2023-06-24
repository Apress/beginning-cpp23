// Range factories and range adaptors
import std;

using namespace std::ranges::views;

bool isEven(int i) { return i % 2 == 0; }
int squared(int i) { return i * i; }

int main()
{
  for (int i : iota(1, 10))       // Lazily generate range [1,10)
    std::print("{} ", i);
  std::println("");

  for (int i : iota(1, 1000) | filter(isEven) | transform(squared) 
                             | drop(2) | take(5) | reverse)
    std::print("{} ", i);
  std::println("");
}
