// Exercise 20-10: exercising projection with range-based algorithms
import std;

int main()
{
  std::vector<std::string> names{"Frodo Baggins", "Gandalf the Gray", 
    "Aragon", "Samwise Gamgee", "Peregrin Took", "Meriadoc Brandybuck", 
    "Gimli", "Legolas Greenleaf", "Boromir"};

  // Sort the names lexicographically
  std::ranges::sort(names);
  std::println("Names sorted lexicographically:\n{:n}", names);
  
  std::println("");

  // Sort the names by length
  /* Projection using member function pointer */
  std::ranges::sort(names, std::less<>{}, &std::string::length);
  /* Alternative: projection using lambda expression */
//  std::ranges::sort(names, std::less<>{}, [](const auto& name) { return name.length(); });
  std::println("Names sorted by length:\n{:n}", names);
}
