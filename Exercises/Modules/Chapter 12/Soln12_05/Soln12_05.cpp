// Using a friend function
import std;
import integer;

int main()
{
  std::println("Create i with the value 10.");
  Integer i {10};
  i.printValue();
  std::println("Change value  of i to 15.");
  i.setValue(15);
  i.printValue();
 
  std::println("Create j from object i.");
  Integer j {i};
  j.printValue();
  std::println("Set value of j to 150 times that of i.");
  j.setValue(150 * i.getValue());
  j.printValue();

  std::println("Create k with the value 789.");
  Integer k {789};
  k.printValue();
  std::println("Set value of k to sum of i and j values.");
  k.setValue(i.getValue() + j.getValue());
  k.printValue();

  std::println("Result of comparing i and j is {}", compare(i, j));
  std::println("Result of comparing k and j is {}", nonFriendCompare(k, j));
}