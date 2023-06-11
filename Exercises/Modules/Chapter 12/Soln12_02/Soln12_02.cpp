// Using a function with a reference parameter in the Integer class
import std;
import integer;

/*****************************************************************\
 Using the version of compare() with the pass-by-value parameter,
 the copy constructor is called because a copy of the argument
 is passed to the function.

 Using the version with the reference parameter a reference
 to the object is passed to the function so no constructor call
 is necessary.

 You cannot overload a function with a reference parameter with
 a function that has a non-reference parameter because the
 compiler cannot tell which function should be called in any
 particular instance.
\*****************************************************************/

int main()
{
  std::println("Create i with the value 0.");
  Integer i;
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

  std::println("Result of comparing i and j is {}", i.compare(j));
  std::println("Result of comparing k and j is {}", k.compare(j));
}