#include <version>
import std;

#ifndef __cpp_lib_format_ranges

namespace impl
{
	template <typename T>
	concept AssociativeContainer = requires { typename T::key_type; };

	template <typename T>
	concept Char = std::same_as<T, char> 
				|| std::same_as<T, wchar_t>;

	template <typename T>
	concept String =                                        // A "String" is (not the best concept definition, obviously)
		Char<std::ranges::range_value_t<T>>					// a range of characters
			&& (!requires { typename T::value_type; }		// that is either not a container (has no value_type member)
				|| requires { typename T::traits_type; });	// or a std::basic_string<> (has a traits_type member)
}

template <std::ranges::input_range T>
requires !impl::String<T> /* && std::formattable<std::ranges::range_value_t<T>> */
struct std::formatter<T> : public std::formatter<std::ranges::range_value_t<T>>
{
	static const char BEGIN = impl::AssociativeContainer<T> ? '{' : '[';
	static const char END = impl::AssociativeContainer<T> ? '}' : ']';

	constexpr auto parse(std::format_parse_context& ctx)
	{
		auto pos = ctx.begin();
		while (pos != ctx.end() && *pos != '}')
		{
			if (*pos == ':')
			{
				ctx.advance_to(++pos);
				return std::formatter<std::ranges::range_value_t<T>>::parse(ctx);
			}
			else if (*pos == 'n')
			{
				m_surround = false;
			}
			++pos;
		}
		return pos;
	}

	auto format(T& range, std::format_context& ctx) const
	{
		auto pos = ctx.out();
		if (m_surround)
		{
			*pos++ = BEGIN;
			ctx.advance_to(pos);
		}
		bool comma{};
		for (auto&& value : range)
		{
			if (std::exchange(comma, true)) { *pos++ = ','; *pos++ = ' '; }
			pos = std::formatter<std::ranges::range_value_t<T>>::format(value, ctx);
			ctx.advance_to(pos);
		}
		if (m_surround)
		{
			*pos++ = END;
		}
		return pos;
	}

	bool m_surround = true;
};

#endif