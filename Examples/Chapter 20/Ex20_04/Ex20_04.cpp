// Basic use of std::map<>
import std;

int main()
{
  std::map<std::string, unsigned long long> phone_book;
  phone_book["Joe"] = 202'456'1111;
  phone_book["Jill"] = 202'456'1111;
  phone_book["Francis"] = 39'06'6982;
  phone_book["Charles"] = 44'020'7930'4832;

  std::println("The pope's number is {}", phone_book["Francis"]);

  for (const auto& [name, number] : phone_book)
    std::println("{} can be reached at {}", name, number);
}
