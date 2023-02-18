module integer;
import std;

Integer::Integer(int value) : m_value{value}
{
  std::println("Object created.");
}

void Integer::printValue() const
{
  std::println("Value is {}.", m_value);
}