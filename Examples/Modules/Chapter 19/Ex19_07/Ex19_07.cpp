// Using a lambda expression from inside a member function (see Finder.cpp)
import std;
import optimum;
import finder;

int main()
{
  std::vector<double> numbers{ 91, 18, 92, 22, 13, 43 };

  int number_to_search_for {};
  std::print("Please enter a number: ");
  std::cin >> number_to_search_for;

  Finder finder;
  finder.setNumberToSearchFor(number_to_search_for);
  std::println("The number nearest to {} is {}", 
      finder.getNumberToSearchFor(), *finder.findNearest(numbers));
}
