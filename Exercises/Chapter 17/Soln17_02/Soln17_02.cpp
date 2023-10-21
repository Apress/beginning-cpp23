// Exercise 16-2
// Create a basic Pair template
import pair;
import std;

int main()
{
  Pair<int, std::string> pair{ 122, "abc" };
  pair.setFirst(pair.getFirst() + 1);
  std::println("pair equals ({}, {})", pair.getFirst(), pair.getSecond());

  using namespace std::string_literals; // To make s suffix work (see below)

  // Yes, CTAD works: no need to specify the template argument list <>...
  Pair pair1{ 0, std::string{ "def" } };  // Option 1: specify std::string yourself (otherwise the type is const char[])
  Pair pair2{ 123, "abc"s };         // Option 2: use string literals: s suffix creates a std::string object
  Pair pair3{ 123, "def"s };

  std::println("{}", pair1 < pair2 && pair2 < pair3 ? "operator< seems to be working" : "oops");
  std::println("{}" , pair1 == pair2 ? "oops" : "operator== works as well");

  std::cout << "Stream insertion operator works just fine as well: " << pair << std::endl;
}