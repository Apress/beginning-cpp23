// Throwing and catching exceptions
import std;

int main()
{
  for (int i {}; i < 5; ++i)
  {
    try
    {
      if (i < 2)
        throw i;

      std::println("i not thrown - value is {}", i);

      if (i > 3)
        throw "Here is another!";

      std::println("End of the try block");
    }
    catch (int i)     // Catch exceptions of type int
    {
      std::println("i caught - value is {}", i);
    }
    catch (const char* message)    // Catch exceptions of type char*
    {
      std::println(R"(message caught - value is "{}")", message);
    }

    std::println("End of the for loop body (after the catch blocks) - i is {}", i);
  }
}
