export module integer;

export class Integer
{
public:
  Integer(int value);
  int getValue() const { return m_value; }
  void setValue(int value) { m_value = value; }
  void printValue() const;

private:
  int m_value;
};
