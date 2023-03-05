// Sneak preview: use copy-and-swap for copy assignment operator
// (see Chapter 17 for details, including the noexcept keyword...)
// In short, you eliminate duplicating the logic of copying an object
// by expressing the copy assignment operator in terms of the copy constructor.
// Less duplication means less room for error, less maintenance overhead, etc.
// Note: this solution is hinted at in a Note in the text, but not explicitly named.
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