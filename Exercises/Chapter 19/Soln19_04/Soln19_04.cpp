// Collecting values using higher-order functions, functors, and lambda expressions.

/*
	There are several ways to check for palindromes. 
	One of the more elegant solutions probably though is the recursive one shown here.
	While recursive lambdas are possible, more or less, recursion is far easier with a regular function.
*/

import std;
import collect;

bool is_palindrome(std::string_view s)
{
  return s.length() == 0
    || (s.front() == s.back() && is_palindrome(s.substr(1, s.length() - 2)));
}

int main()
{
  const std::vector numbers{ -2, 4, -5, 6, 10, -40, 56, 4, 67, 45 };
  std::println("All numbers: {:n}", numbers);
  
  int threshold {};
  std::print("Please enter a threshold: ");
  std::cin >> threshold;
  
  const auto greater{ collect(numbers, [threshold](int i) { return i > threshold; }) };
  std::println("Numbers greater than {}: {:n}", threshold, greater);

  const std::vector letters{ 'C', 'd', 'a', 'z', 't', 'S', 'p', 'm', 'D', 'f' };
  std::println("\nAll characters: {:n}", letters);

  // Note: &std::isupper does not work because there are multiple overloads
  // (one in <cctype> and one in <locale>), making the address-of operator ambiguous.
  // You can take the address of an overloaded function if you want by explicitly specifying the type
  // (in this case using an expression like static_cast<int(*)(int)>(&std::isupper)),
  // but a lambda expression is simply far easier 
  // (and, on top of that, also converts to a function pointer if need be, as you know!).
  const auto capitals{ collect(letters,[](char c) { return std::isupper(c); }) };
  std::println("Capital letters: {:n}", capitals);

  const std::vector<std::string> strings{ "palindrome", "racecar", "rubarb", "noon", "kayak", "ananas", "madam", "backwards" };
  std::println("\nAll strings: {:n}", strings);
  const auto palindromes{ collect(strings, is_palindrome) };
  std::println("Palindromes: {:n}", palindromes);
}