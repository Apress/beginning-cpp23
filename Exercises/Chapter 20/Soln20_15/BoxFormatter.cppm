export module box.formatter;
import box;
import std;

// Adding specific specializations to the std namespace is allowed
export template <>
class std::formatter<Box> : public std::formatter<double>
{
public:
  auto format(const Box& box, auto& context) const  // const was missing in the book...
  {
    auto iter{ std::format_to(context.out(), "Box(") };
    context.advance_to(iter);
    iter = std::formatter<double>::format(box.getLength(), context);
    iter = std::format_to(iter, ", ");
    context.advance_to(iter);
    iter = std::formatter<double>::format(box.getWidth(), context);
    *iter++ = ',';
    *iter++ = ' ';
    context.advance_to(iter);
    std::formatter<double>::format(box.getHeight(), context);
    *iter++ = ')';
    context.advance_to(iter);
    return iter;
  }
};

