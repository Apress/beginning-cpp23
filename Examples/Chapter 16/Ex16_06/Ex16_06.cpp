// Catching any exception
import std;
import troubles;

int main()
{
  for (int i {}; i < 7; ++i)
  {
    try
    {
      try
      {
        if (i == 3)
          throw Trouble{};
        else if (i == 5)
          throw MoreTrouble{};
        else if (i == 6)
          throw BigTrouble{};
      }
      catch (const BigTrouble& bt)
      {
        std::println("Oh dear, big trouble. Let's handle it here and now.");
        // Do not rethrow...
      }
      catch (...)   // Catch any other exception
      {
        std::println("We caught something else! Let's rethrow it.");
        throw;      // Rethrow current exception
      }
    }
    catch (const Trouble& t)
    {
      std::println("{} object caught in outer block: {}", typeid(t).name(), t.what());
    }
    std::println("End of the for loop (after the catch blocks) - i is {}", i);
  }
}
