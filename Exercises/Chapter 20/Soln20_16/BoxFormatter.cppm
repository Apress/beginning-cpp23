export module box.formatter;

import box;
import std;

// Adding specific specializations to the std namespace is allowed
export template <>
class std::formatter<Box>
{
public:
  constexpr auto parse(auto& context)
  {
    if (std::ranges::empty(context))  // May happen for empty {} format specifiers
      return context.begin();

    const auto closing_brace{ std::ranges::find(context, '}') };

    if (closing_brace == context.end()) // If no '}' found, fail
      throw std::format_error{ "missing closing braces, }" };

    const auto length{
        static_cast<std::size_t>(std::ranges::distance(context.begin(), closing_brace)) };
    if (length >= std::size(m_format))  // Leave room for a '\0'!
      throw std::format_error{ "format specifier too long" };
    
    m_no_box = (length && *(closing_brace - 1) == 'n');

    std::ranges::copy(
      context.begin(), 
      m_no_box ? closing_brace - 1 : closing_brace,
      m_format
    );

    return closing_brace;
  }

  auto format(const Box& box, std::format_context& context) const   // const was missing in the book...
  {
    // Not the most efficient approach, but it'll do...
    const auto replacement_field{ std::string{ "{:" } + m_format + '}' };
    const auto length_width_height{ replacement_field + ", " + replacement_field + ", " + replacement_field };
    const auto format{ m_no_box ? length_width_height : "Box(" + length_width_height + ')' };
    const auto args{ std::make_format_args(box.getLength(), box.getWidth(), box.getHeight()) };
    return std::vformat_to(context.out(), format, args);
  }

private:
  bool m_no_box;
  char m_format[100] {};
};
