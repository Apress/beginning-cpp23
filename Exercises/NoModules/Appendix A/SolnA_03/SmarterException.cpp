#include "SmarterException.h"

SmarterException::SmarterException(const std::string& message, std::source_location location)
  : std::logic_error{ message }
  , m_location{ std::move(location) }
{
}

void SmarterException::throwFromHere(std::source_location location)
{
  m_location = std::move(location);
  throw *this;
}

const std::source_location& SmarterException::where() const
{
  return m_location;
}
