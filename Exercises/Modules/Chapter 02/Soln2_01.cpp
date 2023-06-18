// Printing the sizes of numerical types
// Take care: char, signed char, and unsigned char are three different types.

import std;

int main()
{
  std::println("char values occupy {} byte", sizeof(char));
  std::println("signed char values occupy {} byte", sizeof(signed char));
  std::println("unsigned char values occupy {} byte", sizeof(unsigned char));
  
  std::println("short values occupy {} bytes (equivalent: short int, signed short, signed short int)", sizeof(short));
  std::println("unsigned short values occupy {} bytes (equivalent: unsigned short int) ", sizeof(unsigned short));
  std::println("int values occupy {} bytes (equivalent: signed int, signed)", sizeof(int));
  std::println("unsigned int values occupy {} bytes (equivalent: unsigned)", sizeof(unsigned int));
  std::println("long values occupy {} bytes (equivalent: long int, signed long, signed long int)", sizeof(long));
  std::println("unsigned long values occupy {} bytes (equivalent: unsigned long int)", sizeof(unsigned long));
  std::println("long long values occupy {} bytes (equivalent long long int, signed long long, signed long long int)", sizeof(long long));
  std::println("unsigned long long values occupy {} bytes (equivalent: unsigned long long int)", sizeof(unsigned long long));

  std::println("std::size_t values occupy {} bytes", sizeof(std::size_t));

  std::println("float values occupy {} bytes", sizeof(float));
  std::println("double values occupy {} bytes", sizeof(double));
  std::println("long double values occupy {} bytes", sizeof(long double));
}