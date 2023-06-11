module integer;
import std;

void Integer::printValue() const
{
  std::println("Value is {}.", m_value);
}