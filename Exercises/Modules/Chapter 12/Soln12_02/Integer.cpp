module integer;
import std;

// Constructor
Integer::Integer(int value)
  : m_value{ value }
{
  std::println("Object created.");
}

// Copy constructor
Integer::Integer(const Integer& obj) 
  : m_value{ obj.m_value }
{
  std::println("Object created by copy constructor.");
}

// Compare function with reference parameter
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
