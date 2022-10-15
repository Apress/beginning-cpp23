// Exercise 4-6 Finding the range for an integer. 
// This is just a question of bolting sufficient conditional operators together
// in an expression. 

import std;

int main()
{
  int n {};
  std::print("Enter an integer: ");
  std::cin >> n;
  
  std::println("The value is {}.",
      n <= 20 ? "not greater than 20" :
      n <= 30 ? "greater than 20 and not greater than 30" :
      n <= 100 ? "greater than 30 and not exceeding 100" :
                 "greater than 100"
  );
}