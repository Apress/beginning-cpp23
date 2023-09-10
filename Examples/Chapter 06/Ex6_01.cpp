// The size of pointers
import std;

int main()
{
  // Print out the size (in number of bytes) of some data types
  // and the corresponding pointer types:
  std::println("{} > {}", sizeof(double), sizeof(char16_t));
  std::println("{} == {}", sizeof(double*), sizeof(char16_t*));
}
