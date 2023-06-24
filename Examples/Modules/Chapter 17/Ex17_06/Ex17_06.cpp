// Disambiguating dependant base class names
// (this code does not compile without changes)

import std;

template <typename T>
class Base
{
public:
  void baseFun() { /* ... */ }
protected:
  int m_base_var {};
};

template <typename T>
class Derived : public Base<T>
{
public:
  void derivedFun();

protected:
  // Option 3: using declarations
// using Base<T>::baseFun;
// using Base<T>::m_base_var;
};

template <typename T>
void Derived<T>::derivedFun()
{
  // The next two lines should give compiler errors.
  // Uncomment the using declarations in the Derived<> template 
  // to make them work. Alternative solutions are illustrated below.
  baseFun();
  std::println("{}", m_base_var);

  // Option 1: add this->
  this->baseFun();
  std::println("{}", this->m_base_var);

  // Option 2: add Base<T>::
  Base<T>::baseFun();
  std::println("{}", Base<T>::m_base_var);
}

int main()
{
}

