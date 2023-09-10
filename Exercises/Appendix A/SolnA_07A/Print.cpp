import std;

unsigned count;

void print(std::string_view string)
{
  std::println("{}", string);
  ++count;
}
