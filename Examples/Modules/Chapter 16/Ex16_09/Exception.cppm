export module exception;
import std;

export class Exception : public std::exception
{
public:
  Exception(std::string_view message, std::stacktrace trace = std::stacktrace::current())
	: m_message{ message }		// Should use move semantics (twice)
	, m_stack_trace{ trace }
  {}

  const char* what() const override
  {
	  return m_message.c_str();
  }
  const auto& getStackTrace() const
  {
	return m_stack_trace;
  }

private:
  std::string m_message;
  std::stacktrace m_stack_trace;
};
