// A simple C++ customer class

export module customer;

import std;

export class Customer
{
public:
  Customer(
      std::string_view surname,
      std::string_view name,
      std::string_view street,
      int streetNumber,
      std::string_view city
  );

  friend std::string to_string(const Customer& customer);
  
private:
  std::string m_surname;
  std::string m_name;
  std::string m_street;
  int m_streetNumber;
  std::string m_city;
};
