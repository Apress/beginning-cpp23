// Throwing and catching objects in a hierarchy
import std;
import troubles;

int main()
{
  for (int i {}; i < 7; ++i)
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
    catch (const BigTrouble& t)
    {
      std::println("BigTrouble object caught: {}", t.what());
    }
    catch (const MoreTrouble& t)
    {
      std::println("MoreTrouble object caught: {}", t.what());
    }
    catch (const Trouble& t)
    {
      std::println("Trouble object caught: {}", t.what());
    }

    std::println("End of the for loop (after the catch blocks) - i is {}", i);
  }
}
