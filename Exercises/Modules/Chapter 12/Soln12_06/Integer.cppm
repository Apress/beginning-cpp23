export module integer;

export class Integer
{
public:
  Integer(int value = 0);                  // Constructor with given value
  Integer(const Integer& obj);             // Copy constructor
  ~Integer();                              // Destructor

  int getValue() const { return m_value; }
  void setValue(int value) { m_value = value; }

  int compare(const Integer& obj) const;   // Compare function with reference parameter

  void printValue() const;
  
  static void printCount();

private:
  int m_value;
  static inline unsigned int s_count {};
};
