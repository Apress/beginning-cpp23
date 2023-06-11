// Using static members and a destructor to keep track of an object count
import std;
import integer;

void showIntegerVal(Integer it)
{
  it.printValue();
  Integer::printCount();    // passed by value, so object count temporarily increases
}
void showIntegerRef(const Integer& it)
{
  it.printValue();
  Integer::printCount();    // passed by reference, so object count did not increase
}

int main()
{
  std::println("Create i with the value 0.");
  Integer i;
  i.printValue();
  
  Integer::printCount();	// 1 object
 
  if (i.getValue() == 0)
  {
    std::println("Create j from object i.");
    Integer j {i};
    j.printValue();
    Integer::printCount();	// 2 objects
  }
  
  Integer::printCount();	// 1 object again (Integer j was deleted because its scope ended)

  Integer array[] { 1, 2, 3 };
  
  Integer::printCount();   // 4 objects
  
  showIntegerRef(array[0]);
  showIntegerVal(array[1]);
  
  Integer::printCount();   // 4 objects again
}