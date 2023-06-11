// constexpr members...
import std;
import integer;

int main()
{
  // Create the even operands as Integers, 
  // and use implicit conversions from int for the odd values
  constexpr Integer four{4};  // Cannot use four below because constexpr implies const and multiply() is not const...
  constexpr Integer six{6};
  constexpr Integer eight{8};
  
  // We can calculate 4*5*5*5+6*5*5+7*5+8 as:
  //     ((4*5+6)*5+7)*5+8
  constexpr int result{ Integer{ 4 }.multiply(5).add(six).multiply(5).add(7).multiply(5).add(eight).getValue() }; // Set result object as copy of four
  
  std::println("Result is {}", result);
}