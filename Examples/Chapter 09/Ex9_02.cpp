// Working with std::expected<>
import std;

enum class Error { WhoopsADaisy, DisasterStruck, OhMy };
std::expected<std::string, Error> concoctSomeWhatchamacallit(int wobble)
{
  if (wobble < 0)
    return std::unexpected{ Error::WhoopsADaisy };/* Not return Error::WhoopsADaisy;! */
  else
    return "Some superb doohickey";
}


int main()
{
  const auto doohickey = concoctSomeWhatchamacallit(42);

  if (doohickey)
    std::println("{}", *doohickey);
  else
    std::println("An unexpected error occurred (code: {})", static_cast<int>(doohickey.error()));
}
