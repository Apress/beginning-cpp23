export module integer;

export class Integer
{
public:
  constexpr Integer(int value = 0);
  // Implicit copy constructor is implicitly constexpr...

  constexpr int getValue() const { return m_value; }
  constexpr void setValue(int value) { m_value = value; }
  
  constexpr Integer& add(const Integer& obj);
  constexpr Integer& subtract(const Integer& obj);
  constexpr Integer& multiply(const Integer& obj);

  constexpr int compare(const Integer& obj) const;
  
  void printValue() const;

private:
  int m_value;
};


// Constructor
constexpr Integer::Integer(int value)
    : m_value{ value }
{
}

constexpr Integer& Integer::add(const Integer& obj)
{
    m_value += obj.m_value;
    return *this;
}

constexpr Integer& Integer::subtract(const Integer& obj)
{
    m_value -= obj.m_value;
    return *this;
}

constexpr Integer& Integer::multiply(const Integer& obj)
{
    m_value *= obj.m_value;
    return *this;
}

constexpr int Integer::compare(const Integer& obj) const
{
    if (m_value < obj.m_value)
        return -1;
    else if (m_value == obj.m_value)
        return 0;
    else
        return 1;
}
