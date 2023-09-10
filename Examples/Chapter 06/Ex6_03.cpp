// Initializing pointers with strings
import std;

int main()
{
  const char* pstar1 {"Fatty Arbuckle"};
  const char* pstar2 {"Clara Bow"};
  const char* pstar3 {"Lassie"};
  const char* pstar4 {"Slim Pickens"};
  const char* pstar5 {"Boris Karloff"};
  const char* pstar6 {"Mae West"};
  const char* pstar7 {"Oliver Hardy"};
  const char* pstar8 {"Greta Garbo"};
  
  std::print("Pick a lucky star! Enter a number between 1 and 8: ");
  unsigned choice {};
  std::cin >> choice;

  switch (choice)
  {
  case 1: std::println("Your lucky star is {}.", pstar1); break;
  case 2: std::println("Your lucky star is {}.", pstar2); break;
  case 3: std::println("Your lucky star is {}.", pstar3); break;
  case 4: std::println("Your lucky star is {}.", pstar4); break;
  case 5: std::println("Your lucky star is {}.", pstar5); break;
  case 6: std::println("Your lucky star is {}.", pstar6); break;
  case 7: std::println("Your lucky star is {}.", pstar7); break;
  case 8: std::println("Your lucky star is {}.", pstar8); break;
  
  default: std::println("Sorry, you haven't got a lucky star.");
  }
}
