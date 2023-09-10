// Modifying the value of a caller variable – references vs pointers
import std;

void change_it_by_pointer(double* pointer_to_it);     // Pass pointer (by value)
void change_it_by_reference(double& reference_to_it); // Pass by reference

int main()
{
  double it {5.0};

  change_it_by_pointer(&it);   // Now we pass the address
  std::println("After first function execution, it = {}", it);

  change_it_by_reference(it);  // Now we pass a reference, not the value!
  std::println("After second function execution, it = {}", it);
}

void change_it_by_pointer(double* pointer_to_it)
{
  *pointer_to_it += 10.0;   // This modifies the original double
}
void change_it_by_reference(double& reference_to_it)
{
  reference_to_it += 10.0;  // This modifies the original double as well!
}
