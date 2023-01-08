// Exercise 5-1 Squaring odd numbers
import std;

int main()
{
  unsigned long long limit {};
  std::print("Enter the upper limit for squared odd numbers: ");
  std::cin >> limit;
  for (unsigned long long i {1}; i <= limit; i += 2)
  {
    std::println("{:4} squared is {:8}", i, i * i);
  }
}