// Exercise 18-4
/* 
  Below is the same test program as used in Exercise 16-6, 
  with some additional lines to show that the RAII objects can be moved.
*/

import std;

#include "DB.h"
import db.exception;
import db.raii;
import customer;

void verifyCustomerFields(DB_QUERY_RESULT* result);           // Sanity check on the number of fields returned by our query
std::vector<Customer> readCustomers(DB_QUERY_RESULT* result); // Convert the DB result to a series of C++ objects

int main()
{
  DBConnectionRAII connection{ db_connect() };
  DBConnectionRAII moved_connection{ std::move(connection) };
  
  try
  {
    DBQueryResultRAII result{ db_query(moved_connection, "SELECT * FROM CUSTOMER_TABEL") };
    if (!result)
    {
      throw DatabaseException{"Query failed"};
    }
	
	DBQueryResultRAII moved_result;
	moved_result = std::move(result);
	
    std::vector<Customer> customers{ readCustomers(moved_result) };
  
  if (customers.empty())
  {
    std::println("No customers found?");
    return 2;
  }
    
  for (auto& customer : customers)
  {
     std::println("{}", to_string(customer));
  }
  }
  catch (std::exception& caught)
  {
    std::println("{}", caught.what());
    return 1;
  }
}

std::vector<Customer> readCustomers(DB_QUERY_RESULT* result)
{
  // Sanity check 
  // (if the number of fields does not match 5, 
  // the code below would crash!)
  verifyCustomerFields(result);
   
  std::vector<Customer> customers;
  
  auto row{ db_fetch_row(result) };
  while (row)
  {
    customers.push_back(Customer{
      row[0],            // Surname
      row[1],            // Name
      row[2],            // Street
      std::stoi(row[3]), // Street number
      row[4]             // City
    });
    
    row = db_fetch_row(result);
  }
  
  return customers;
}

void verifyCustomerFields(DB_QUERY_RESULT* result)
{
  int numFields{ db_num_fields(result) };
  if (numFields < 0)
  {
    throw DatabaseException{"db_num_fields() failed"};
  }
  if (numFields != 5)
  {
    throw DatabaseException{"Unexpected number of fields: " + std::to_string(numFields)};
  }
}
