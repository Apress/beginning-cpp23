// Working with sets
import std;

int main()
{
  std::set<int> my_set;

  // Insert elements 1 through 4 in arbitrary order:
  my_set.insert(1);
  my_set.insert(4);
  my_set.insert(3);
  my_set.insert(3);  // Elements 3 and 1 are added twice
  my_set.insert(1);
  my_set.insert(2);

  std::println("There are {} elements in my_set: {:n}", my_set.size(), my_set);
  std::println("The element 1 occurs {} time(s)", my_set.count(1));

  // Like all containers, sets are ranges...
  int sum {};
  for (int x : my_set) sum += x; // ... and can thus be used in a range-based loop
  std::println("The sum of the elements is {}", sum);

  my_set.erase(1);   // Remove the element 1 once
  std::println("After erase(1), my_set holds {} elements: {:n}", my_set.size(), my_set);

  my_set.clear();    // Remove all elements
  std::println("After clear(), my_set holds {} elements: {:n}", my_set.size(), my_set);
}