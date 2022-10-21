// Embedding a stack trace in an exception
import std;
import exception;

int f3() { throw Exception{ "Something's amis!" }; }
int f2() { return f3(); }
int f1() { return f2(); }

int main()
{
  try
  {
    f1();
  }
  catch (const Exception& ex)
  {
    std::println("Exception of type {} caught: {}; trace:\n{}", 
        typeid(ex).name(), ex.what(), to_string(ex.getStackTrace()));
  }
}
