// A custom exception class that carries a stack trace
export module tracing_exception;
import std;

export class TracingException : public std::exception
{
public:
  TracingException(
    std::string_view message, 
    std::stacktrace trace = std::stacktrace::current()
  )
    : m_message{ message }    // Should use move semantics (twice): see Chapter 18
    , m_trace{ trace }
  {}

  const char* what() const noexcept override { return m_message.c_str(); }
  const auto& getTrace() const noexcept { return m_trace; }

private:
  std::string m_message;
  std::stacktrace m_trace;
};
