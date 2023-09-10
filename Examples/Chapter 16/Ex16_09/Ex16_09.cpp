// Embedding a stack trace in an exception
import std;
import tracing;

int f3() { throw TracingException{ "Something's amiss!" }; } // Obtains a stacktrace!
int f2() { return f3(); }
int f1() { return f2(); }

int main()
{
  try
  {
    f1();
  }
  catch (const TracingException& ex)
  {
    std::println("Exception of type {} caught: {}; trace:\n{}", 
        typeid(ex).name(), ex.what(), ex.where());
  }
}
