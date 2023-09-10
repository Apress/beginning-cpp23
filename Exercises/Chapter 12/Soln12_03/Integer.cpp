module integer;
import std;

// Constructor
Integer::Integer(int value) 
  : m_value{ value }
{
}

// Copy constructor
Integer::Integer(const Integer& obj) 
  : m_value{obj.m_value} 
{
}

Integer& Integer::add(const Integer& obj)
{ 
  m_value += obj.m_value;
  return *this;
}

Integer& Integer::subtract(const Integer& obj) 
{
  m_value -= obj.m_value;
  return *this;
}

Integer& Integer::multiply(const Integer& obj) 
{
  m_value *= obj.m_value;
  return *this;
}

int Integer::compare(const Integer& obj) const
{
  if (m_value < obj.m_value)
    return -1;
  else if (m_value == obj.m_value)
    return 0;
  else
  	return 1;
}

void Integer::printValue() const
{
  std::println("Value is {}.", m_value);
}