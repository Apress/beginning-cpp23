export module dimension_error;

import std;

export class DimensionError : public std::out_of_range
{
public:
  explicit DimensionError(double value)
    : std::out_of_range{ "Zero or negative dimension: " + std::to_string(value) }
    , m_value{ value } {}

  // Function to obtain the invalid dimension value
  double getValue() const noexcept { return m_value; }
private:
  double m_value;
};
