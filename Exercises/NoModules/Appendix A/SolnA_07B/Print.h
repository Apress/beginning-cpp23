#ifndef PRINT_H
#define PRINT_H

// Caution: no imports in header files...
#include <print>
#include <string_view>

inline int count {};

inline void print(std::string_view string)
{
  std::println("{}", string);
  ++count;
}

#endif