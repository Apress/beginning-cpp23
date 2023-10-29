# Workarounds

At the time the book was completed, 
not a single compiler [supported](https://en.cppreference.com/w/cpp/compiler_support) all C++23 features yet. 
Assuming you use one of the latest mainstream compilers,
features for which you may need a workaround to compile and run the example / exercise code include

- [Modules](#modules)
- [std::print() / std::println()](#print)
- [Formatting ranges](#formatting_ranges)

> [!NOTE]
> If you are using a compiler that , 
> you may also want to look at the [workarounds for the C++20 edition of the book](https://github.com/Apress/beginning-cpp20/tree/main/Workarounds).

<a name="modules"/>

## Modules

Only Visual Studio has complete support for C++ modules,
which is why we recommend you to use this compiler until further notice,
as explained also in our [compilation guide](../Compiling.md).

<a name="print"/>

## std::print() and std::println()

While we expect Standard Library implementations to catch up soon, 
`std::print()` and `std::println()` are not universally supported yet.
You can work around this by injecting [`print_workaround.h`](print_workaround.h) into your source code
(either explicitly by including the header yourself, 
or implicitly through compiler options such as 
[`/FI`](https://learn.microsoft.com/en-us/cpp/build/reference/fi-name-forced-include-file?view=msvc-170) in Visual Studio and the `-include` command-line flags for GCC and Clang).

<a name="formatting_ranges"/>

## Formatting Ranges

Even if your library supports `std::print()` and `std::println()` already,
it may not yet be able to format ranges.
You can work around this by injecting [`format_ranges_workaround.h`](format_ranges_workaround.h) into your source code.
