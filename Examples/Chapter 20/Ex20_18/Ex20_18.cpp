// Writing through a view
import std;

bool isEven(int i) { return i % 2 == 0; }

int main()
{
  std::vector numbers{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  for (int& i : numbers | std::views::filter(isEven))
    i *= i;

  std::println("{}", numbers);
}
