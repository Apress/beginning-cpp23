#ifndef SMARTER_EXCEPTION_H
#define SMARTER_EXCEPTION_H

#include <stdexcept>
#include <source_location>

class SmarterException : public std::logic_error
{
public:
  SmarterException(const std::string& message, std::source_location location = std::source_location::current())
    : std::logic_error{ message }
    , m_location{ std::move(location) }
  {
  }

  const std::source_location& where() const;

private:
  std::source_location m_location;
};

inline const std::source_location& SmarterException::where() const
{
  return m_location;
}

#endif
