// Using the continue statement to display ASCII character codes
import std;

int main()
{
  // 3 cols., 11 wide, centered (^)
  std::println("{:^11}{:^11}{:^11}", "Character", "Hexadecimal", "Decimal");

  // Output 7-bit ASCII characters and corresponding codes
  for (int ch {}; ch <= 127; ++ch)
  {
    if (!std::isprint(ch))  // If it's not printable...
      continue;             // ...skip this iteration
    std::println("{0:^11}{0:^11X}{0:^11d}", static_cast<char>(ch)); // Print 3 times
  }
}
