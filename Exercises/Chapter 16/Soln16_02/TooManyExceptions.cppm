// Definition of TooManyExceptions exception class
// We added an extra "how many" members to illustrate derived 
// exceptions can carry extra information regarding their cause.
// Notice how the constructor is explicit (implicit conversions
// from std::size_t to TooManyExceptions are not desired).

export module too_many;
import std;

export class TooManyExceptions : public std::exception
{
public:
  explicit TooManyExceptions(unsigned howMany)
    : m_how_many{ howMany }
    , m_message{ "Too many exceptions occurred: " + std::to_string(m_how_many) }
  {}

  const char* what() const noexcept override
  {
    return m_message.c_str();
  }

  unsigned howMany() const noexcept
  {
    return m_how_many;
  }

private:
  unsigned m_how_many;
  std::string m_message;
};
