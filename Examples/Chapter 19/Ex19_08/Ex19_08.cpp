// Using the std::function<> template
import std;

// A global less() function
bool less(int x, int y) { return x < y; }

int main()
{
  const int a{ 18 }, b{ 8 };  

  std::function<bool(int,int)> compare;

  compare = less;              // Store a function pointer into compare
  std::println("{} < {}: {}", a, b, compare(a, b));

  compare = std::greater<>{};  // Store a function object into compare
  std::println("{} > {}: {}", a, b, compare(a, b));

  int n{ 10 };                 // Store a lambda closure into compare
  compare = [n](int x, int y) { return std::abs(x - n) < std::abs(y - n); };
  std::println("{} nearer to {} than {}: {}", a, n, b, compare(a, b));

  // Check whether a function<> object is tied to an actual function
  std::function<void(const int&)> empty;
  if (empty)             // Or, equivalently: 'if (empty != nullptr)'
  {
    std::println("Calling a default-constructed std::function<>?");
    empty(a);
  }
}
