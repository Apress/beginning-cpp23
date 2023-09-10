// Finding the largest of two integers without comparing them.
import std;

int main()
{
  unsigned a {};
  unsigned b {};

  std::print("Enter a positive integer: ");
  std::cin >> a;
  std::print("Enter another positive integer: ");
  std::cin >> b;

  // The trick is that, for integer values a and b, 
  // a / b equals zero if a < b.
  // So unless a and b are equal, either a/b or b/a is zero,
  // meaning in (x * (a/b) + y * (b/a)) one of both operands of + equals 0.
  // Once you have that, it's just a matter of working out the details.

  const unsigned larger {(a * (a / b) + b * (b / a)) / (a / b + b / a)};
  const unsigned smaller {(b * (a / b) + a * (b / a)) / (a / b + b / a)};
  std::println("The larger integer is {}.", larger);
  std::println("The smaller integer is {}.", smaller);
}