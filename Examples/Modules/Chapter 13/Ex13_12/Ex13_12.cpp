// Defining a copy assignment operator
import message;
import std;

int main()
{
  Message beware{ "Careful" };
  Message warning;
  
  warning = beware;    // Call assignment operator

  std::println("After assignment beware is: {}", beware.getText());
  std::println("After assignment warning is: {}", warning.getText());
}