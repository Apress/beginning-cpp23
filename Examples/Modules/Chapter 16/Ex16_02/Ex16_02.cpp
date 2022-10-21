// Throw an exception object
import std;
import troubles;

void trySomething(int i);

int main()
{
  for (int i {}; i < 2; ++i)
  {
    try
    {
      trySomething(i);
    }
    catch (const Trouble& t)
    {
      // What seems to be the trouble?
      std::println("Exception: {}", t.what());
    }
  }
}

void trySomething(int i)
{
  // There's always trouble when ‘trying something’...
  if (i == 0)
    throw Trouble {};
  else
    throw Trouble {"Nobody knows the trouble I've seen..."};
}
