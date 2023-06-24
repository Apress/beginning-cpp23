#include "SmarterException.h"

SmarterException::SmarterException(const std::string& message, std::source_location location)
  : std::logic_error{ message }
  , m_location{ std::move(location) }
{
}

const std::source_location& SmarterException::where() const
{
  return m_location;
}
