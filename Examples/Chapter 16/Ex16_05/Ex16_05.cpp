// Rethrowing exceptions
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
      catch (const Trouble& t)
      {
        if (typeid(t) == typeid(Trouble))
          std::println("Trouble object caught in inner block: {}", t.what());
        else
          throw;     // Rethrow current exception
      }
    }
    catch (const Trouble& t)
    {
      std::println("{} object caught in outer block: {}", typeid(t).name(), t.what());
    }
    std::println("End of the for loop (after the catch blocks) - i is {}", i);
  }
}
