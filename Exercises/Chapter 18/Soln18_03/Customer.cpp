// A simple C++ customer class

module customer;

Customer::Customer(
      std::string_view surname,
      std::string_view name,
      std::string_view street,
      int streetNumber,
      std::string_view city)
  : m_surname{ surname }
  , m_name{ name }
  , m_street{ street }
  , m_streetNumber{ streetNumber }
  , m_city{ city }
{}

std::string to_string(const Customer& customer)
{
  std::string result;
  result += customer.m_surname;
  result += ' ';
  result += customer.m_name;
  result += ", ";
  result += customer.m_street;
  result += ' ';
  result += std::to_string(customer.m_streetNumber);
  result += ", ";
  result += customer.m_city;
  return result;
}