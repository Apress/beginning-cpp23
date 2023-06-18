// Overloading a unary "rotate" operator
import std;
import box;

int main()
{
  Box someBox{ 1, 2, 3 };
  std::println("{}", to_string( ~someBox ));
}
