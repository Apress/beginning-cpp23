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

    m_no_box = (closing_brace != context.begin() && *(closing_brace - 1) == 'n');

    std::string double_format{ context.begin(), closing_brace };
    if (m_no_box)
      double_format.pop_back(); // Take out the 'n'

    std::format_parse_context double_formatter_context{ double_format };
    m_double_formatter.parse(double_formatter_context);

    return closing_brace;
  }

  auto format(const Box& box, auto& context) const  // const was missing in the book...
  {
    auto iter{ context.out() };
    if (!m_no_box)
      iter = std::format_to(context.out(), "Box(");
    context.advance_to(iter);
    iter = m_double_formatter.format(box.getLength(), context);
    iter = std::format_to(iter, ", ");
    context.advance_to(iter);
    iter = m_double_formatter.format(box.getWidth(), context);
    *iter++ = ',';
    *iter++ = ' ';
    context.advance_to(iter);
    m_double_formatter.format(box.getHeight(), context);
    if (!m_no_box)
      *iter++ = ')';
    context.advance_to(iter);
    return iter;
  }

private:
  bool m_no_box;
  std::formatter<double> m_double_formatter;
};
