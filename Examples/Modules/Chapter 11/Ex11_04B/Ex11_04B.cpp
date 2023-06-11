// Module implementation partitions
import std;
import roman;

int main()
{
  std::println("1234 in Roman numerals is {}", to_roman(1234));
  std::println("MMXX in Arabic numerals is {}", from_roman("MMXXIII"));
}
