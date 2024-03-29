// A class of function objects that compare two values based on how close they are 
// to some third value that was provided to the functor at construction time.
export module nearer;
import std;   // For std::abs()

export class Nearer
{
public:
  explicit Nearer(int value) : m_value{ value } {}
  bool operator()(int x, int y) const
  { 
    return std::abs(x - m_value) < std::abs(y - m_value); 
  }
private:
  int m_value;
};

