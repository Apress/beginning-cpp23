// Definition of Curveball exception class

export module curveball;
import std;

export class Curveball : public std::exception
{
public:
  const char* what() const noexcept override
  {
    return "Curveball exception";
  }
};
