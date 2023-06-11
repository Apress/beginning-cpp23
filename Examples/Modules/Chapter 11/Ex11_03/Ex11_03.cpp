// Using types with reachable definitions but whose names are not visible
// Note: we added [[maybe_unused]] annotations to silence compiler warnings
// (remove them, and your compiler will likely warn that for instance num_numerals is never used...)

import roman;

int main()
{
  // Even though the std::string and std::string_view names are not visible,
  // their reachability implies that the names of their constructors and destructors (see Chapter 12) are visible...
  from_roman("DCLXVI"); // Creates std::string_view object to invoke from_roman(string_view)
  to_roman(1234);      // Receives and destructs the string object returned by to_roman(int)

  // In fact, the name of any member function, not just the constructor or destructor,
  // of a reachable type is visible. The name of the size() member of std::string is therefore visible,
  // meaning this member function can therefore be invoked...
  [[maybe_unused]]
  const auto num_numerals{ to_roman(1234).size() }; // 8 numerals ("MCCXXXIV")
  
  // Even though you cannot use the invisible std::string / std::string_view names,
  // you can still capture objects of these types using auto / const auto&...
  
// std::string_view s{ "MMXXIII" };/* Error: the name std::string_view is not visible */
// std::string roman{ to_roman(567) };  /* Error: the name std::string is not visible */
  
  const auto roman{ to_roman(789) };      // "DCCLXXXIX"
  [[maybe_unused]]
  const auto first_X{ roman.find('X') };  // 4
  
  // auto i{ std::stoi(to_roman(567)) }; /* Error: the name std::stoi is not visible */
}
