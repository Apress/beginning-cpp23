export module pair;
import std;

export template <typename First, typename Second>
class Pair
{
public:
  Pair() = default;
  Pair(const First& first, const Second& second);

  // Defined out-of-class
  const First& getFirst() const;
  void setFirst(const First& first);

  // Defined in-class
  const Second& getSecond() const { return m_second; }
  void setSecond(const Second& second) { m_second = second; }

  // Long live modern compilers: no code needed at all!
  auto operator<=>(const Pair& other) const = default;

private:
  First m_first;
  Second m_second;
};

export template <typename First, typename Second>
std::ostream& operator<<(std::ostream& out, const Pair<First, Second>& pair)
{
  return out << '(' << pair.getFirst() << ", " << pair.getSecond() << ')';
}

template <typename First, typename Second>
Pair<First, Second>::Pair(const First& f, const Second& s)
  : m_first{f}, m_second{s}
{}

template <typename First, typename Second>
const First& Pair<First, Second>::getFirst() const
{
  return m_first;
}

template <typename First, typename Second>
void Pair<First, Second>::setFirst(const First& f)
{
  m_first = f;
}
