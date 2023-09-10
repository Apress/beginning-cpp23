// Throwing and catching standard exceptions
import std;

/*
  This solution triggers all exceptions mentioned in the text 
  accompanying the Table with all Standard Library exceptions, in order.
  To know how to trigger any other type, 
  you will have to consult your Standard Library reference.

  Note: while you'll typically catch exceptions by reference-to-const-std::exception 
  (unless more specific handling for concrete types is required, of course),
  we specify the concrete exception type instead here for clarity.
 */

// First, some dummy class types...
class BaseClass
{
public:
  virtual ~BaseClass() = default;
};

class DerivedClass1 : public BaseClass {};
class DerivedClass2 : public BaseClass {};

int main()
{
  try
  {
    std::vector v{ 1, 2, 3, 4, 5 };
    std::println("{}", v.at(10));
  }
  catch (const std::out_of_range& exception)
  {
    std::println("std::out_of_range: {}", exception.what());
  }

  try
  {
    std::cout << std::vformat("Hello {:g}!\n", std::make_format_args("World"));
  }
  catch (const std::format_error& exception)
  {
    std::println("std::format_error: {}", exception.what());
  }

  try
  {
    // Remember: a polymorphic class is a class with at least one virtual function.
    BaseClass* polymorphic{ nullptr };
    std::println("{}", typeid(*polymorphic).name());
  }
  catch (const std::bad_typeid& exception)
  {
    std::println("std::bad_typeid: {}", exception.what());
  }

  try
  {
    DerivedClass1 derived;
    BaseClass& reference_to_base{ derived };
    dynamic_cast<DerivedClass2&>(reference_to_base);
  }
  catch (const std::bad_cast& exception)
  {
    std::println("std::bad_cast: {}", exception.what());
  }

  try
  {
    std::optional<int> empty;
    std::println("{}", empty.value());
  }
  catch (const std::bad_optional_access& exception)
  {
    std::println("std::bad_optional_access: {}", exception.what());
  }

  try
  {
    std::expected<std::string, int> error{ std::unexpected(123) };
    std::println("{}", error.value());
  }
  catch (const std::bad_expected_access<int>& exception)
  {
    std::println("std::bad_expected_access: {} (error: {})", exception.what(), exception.error());
  }

  try
  {
    int size{ -1 };
    new int[size];
  }
  catch (const std::bad_alloc& exception)
  {
    std::println("std::bad_alloc: {}", exception.what());
  }
}
