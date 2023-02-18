/*****************************************************************\
 To implement printCount(), you first need a static member variable
 to store the object count. Every constructor should then increment
 this count, and you need to add a destructor that decrements it. 
\*****************************************************************/
module integer;
import std;

// Constructor
Integer::Integer(int value) : m_value{value}
{
  ++s_count;
  std::println("Object created.");
}

// Copy constructor
Integer::Integer(const Integer& obj) : m_value{obj.m_value}
{
  ++s_count;
  std::println("Object created by copy constructor.");
}

// Destructor
Integer::~Integer()
{
  --s_count;
  std::println("Object deleted.");
}

void Integer::printValue() const
{
  std::println("Value is {}.", m_value);
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

void Integer::printCount()
{
  std::println("There are now {} Integer object(s).", s_count);
}