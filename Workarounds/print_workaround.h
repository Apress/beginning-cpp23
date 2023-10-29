#include <version>
import std;

#ifndef __cpp_lib_print
namespace std
{
	template <typename... Args>
	void print(const format_string<Args...> format, Args&&... args)
	{
		std::format_to(std::ostreambuf_iterator<char>(std::cout), format, std::forward<Args>(args)...);
	}
	
	template <typename... Args>
	void println(const format_string<Args...> format, Args&&... args)
	{
		print(format, std::forward<Args>(args)...);
		std::cout << '\n';
	}

	template <typename... Args>
	void print(const wformat_string<Args...> format, Args&&... args)
	{
		std::format_to(std::ostreambuf_iterator<wchar_t>(std::wcout), format, std::forward<Args>(args)...);
	}

	template <typename... Args>
	void println(const wformat_string<Args...> format, Args&&... args)
	{
		print(format, std::forward<Args>(args)...);
		std::wcout << L'\n';
	}
}
#endif