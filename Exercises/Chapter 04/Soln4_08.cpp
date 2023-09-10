// Exercise 4-8
// Dividing a cash amount into quarters, nickels, dimes and cents.

import std;

int main()
{
  // Declare the constants (amounts of cents)
  const unsigned quarter {25};
  const unsigned dime {10};
  const unsigned nickel {5};

  double amountInDollars {0.0};
  std::print("Please enter a cash amount between 0 and 10 dollars: $");
  std::cin >> amountInDollars;
  
  if (amountInDollars >= 0.0 && amountInDollars <= 10.0)
  {
    // Multiply dollar amount by 100 ($1 = 100 cents)
    // We add 0.5 to compensate for errors in binary floating-point representation
    auto amountInCents {static_cast<unsigned>(amountInDollars * 100.0 + 0.5)};

    // Find the number of quarters
    const auto quarters {amountInCents / quarter};
    amountInCents %= quarter;               // Get the remainder

    // Find the number of dimes
    const auto dimes {amountInCents / dime};
    amountInCents %= dime;                  // Get the remainder

    // Find the number of nickels
    const auto nickels {amountInCents / nickel};
    amountInCents %= nickel;                // Get the remainder

    // Find the number of pennies
    const auto pennies {amountInCents};     // The remainder is already in pennies

    std::println("\nThe dollar value ${} can be broken down into:", amountInDollars);
    std::println("\t{} quarter{},", quarters, (quarters == 1 ? "" : "s"));
    std::println("\t{} dime{},", dimes, (dimes == 1 ? "" : "s"));
    std::println("\t{} nickel{},", nickels, (nickels == 1 ? "" : "s"));
    std::println("\t{} penn{}.", pennies, (pennies == 1 ? "y" : "ies"));
  }
  else
  {
    std::println("\nYou did not enter a dollar amount between 0 and 10.");
  }
}