export module message;
import std;

export class Message
{
public:
  explicit Message(const char* text = "")
    : m_text(new char[std::strlen(text) + 1]) // Caution: include the null character!
  {
    std::strcpy(m_text, text);        // Mind the order: strcpy(destination, source)!
  }
  ~Message() { delete[] m_text; }

  Message& operator=(const Message& message); // Assignment operator

  const char* getText() const { return m_text; }

private:
  char* m_text;
};
