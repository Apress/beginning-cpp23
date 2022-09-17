// Using the continue statement to display ASCII character codes
import <iostream>;
import <print>;

#include <cctype>

int main()
{
  constexpr auto header_format = "{:^11}{:^11}{:^11}";  // 3 cols., 11 wide, centered (^)
  constexpr auto body_format = "{0:^11}{0:^11X}{0:^11d}"; // Print same value three times

  std::println(header_format, "Character", "Hexadecimal", "Decimal");

  // Output 7-bit ASCII characters and corresponding codes
  char ch{};
  do
  {
    if (!std::isprint(ch))  // If it's not printable...
      continue;             // ...skip this iteration
    std::println(body_format, ch);
  } while (ch++ < 127);
}
