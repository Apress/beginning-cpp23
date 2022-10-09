// Exception class definition
export module troubles;
import std;

export class Trouble
{
public:
  explicit Trouble(std::string_view message = "There's a problem") 
    : m_message {message} 
  {}
  std::string_view what() const { return m_message; }
private:
  std::string m_message;
};
