// Always define both copy members together
// (see also 'Rule of Five' in Chapter 18!)
import message;
import std;

int main()
{
  Message beware{ "Careful" };
  Message warning;
  
  warning = beware;    // Call assignment operator

  Message caution{ warning };

  std::println("After assignment beware is: {}", beware.getText());
  std::println("After assignment warning is: {}", warning.getText());
  std::println("As a copy of warning, caution is: {}", caution.getText());
}