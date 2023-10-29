# Workarounds

At the time the book was completed, 
not a single compiler [supported](https://en.cppreference.com/w/cpp/compiler_support) all C++23 features yet. 
Assuming you use one of the latest mainstream compilers,
features for which you may need a workaround to compile and run the example / exercise code include

- [Modules](#modules)
- [std::print() / std::println()](#print)
- [Formatting ranges](#formatting_ranges)

> [!NOTE]
> If you are using an older compiler, or any other compiler with less support for modern C++, 
> you may also want to look at the [workarounds for the C++20 edition of the book](https://github.com/Apress/beginning-cpp20/tree/main/Workarounds).

<a name="modules"/>

## Modules

At the time of writing, only Visual Studio has complete support for C++ modules,
which is why we highly recommend you to use this compiler in our [compilation guide](../Compiling.md).

We are still working out whether compiling modules with compilers such as GCC and Clang is feasible,
but we've heard it's not for the faint of heart.
If you cannot use Visual Studio, for some reason (you do not have a Windows pc),
it may thus be easier to replace module `import`s with header `#include`s,
and module files with corresponding header and source files.
Appendix A of the book contains all information you need to do so.
The [source repository of the C++20 edition of the book](https://github.com/Apress/beginning-cpp20/) 
also still contains versions of examples and exercise solutions without the use of modules.
For most of our C++23 examples and exercises you can easily find a direct C++20 equivalent there.

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
