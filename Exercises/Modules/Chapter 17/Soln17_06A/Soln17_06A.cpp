// Implementing a custom std::formatter<> specialization to format Box objects
// (Alternate solution)
import box;
import box.formatter;
import std;

enum class Error { WhoopsADaisy, DisasterStruck, OhMy };
std::expected<std::string, Error> concoctWhatchamacallit(int wobble)
{
    if (wobble < 0)
        return std::unexpected(Error::WhoopsADaisy); // Not return Error::WhoopsADaisy;!
    else
        return "Doohickey";
}


consteval auto test()
{
    std::formatter<Box> formatter;

    std::basic_format_parse_context<char> test("{:.2}", 1);
    formatter.parse(test);
    return formatter;
}

int main()
{
  Box box{ 1, 2, 3 };
  std::println("My new box, {:.2}, is fabulous!", box);

  constexpr auto x = test();
}