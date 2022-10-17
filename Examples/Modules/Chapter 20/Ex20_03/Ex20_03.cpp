// Ex20_03.cpp - Working with sets
import std;

void printSet(const std::set<int>& my_set);  // Print the contents of a set

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

  printSet(my_set);

  std::println("The element 1 occurs {} time(s)", my_set.count(1));

  my_set.erase(1);   // Remove the element 1 once
  printSet(my_set);

  my_set.clear();    // Remove all elements
  printSet(my_set);
}

void printSet(const std::set<int>& my_set)
{
  std::print("There are {} elements in my_set: ", my_set.size());
  for (int element : my_set)       // A set, like all containers, is a range
    std::print("{} ", element);
  std::println("");
}
