// A simple C++ exception type

export module db.exception;

import std;

export class DatabaseException : public std::runtime_error
{
public:
  using std::runtime_error::runtime_error;  // Inherit constructor
};

