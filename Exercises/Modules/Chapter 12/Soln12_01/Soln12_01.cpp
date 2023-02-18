// Implementing an Integer class
import integer;
import std;

int main() 
{
  std::println("Create i with the value 10.");
  Integer i {10};
  i.printValue();
  std::println("Change value  of i to 15.");
//  i.m_value = 15;	// Cannot assign directly to m_value
  i.setValue(15);
  i.printValue();
 
  std::println("Create j with a value that is 150 times that of i.");
  const Integer j {150 * i.getValue()};
  j.printValue();
  std::println("Set value of j to 5,000.");
// j.setValue(5'000); // Cannot call setValue() on const object 
                      // (printValue() and getValue() work, though)

  std::println("Create k with the value 789.");
  Integer k {789};
  k.printValue();
  std::println("Set value of k to sum of i and j values.");
  k.setValue(i.getValue() + j.getValue());
  k.printValue();
}