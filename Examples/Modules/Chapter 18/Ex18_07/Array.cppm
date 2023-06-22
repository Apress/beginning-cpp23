export module array;

// Exact same as template as Ex18_05B (that is: without noexcept specifiers!)

import std;

export template <typename T>
class Array
{
public:
  Array();                                    // Default constructor
  explicit Array(std::size_t size);           // Constructor
  ~Array();                                   // Destructor
  Array(const Array& array);                  // Copy constructor
  Array(Array&& array) /*noexcept*/;          // Move constructor
  Array& operator=(const Array& rhs);         // Copy assignment operator
  Array& operator=(Array&& rhs) /*noexcept*/; // Move assignment operator
  void swap(Array& other) noexcept;           // noexcept swap function
  T& operator[](std::size_t index);           // Subscript operator
  const T& operator[](std::size_t index) const; // Subscript operator-const arrays
  std::size_t getSize() const noexcept { return m_size; }   // Accessor for m_size
  void push_back(T element);      // Copy or move element to the back of the array

private:
  T* m_elements;      // Array of elements of type T
  std::size_t m_size; // Number of array elements
};

// Forwarding default constructor template
template <typename T>
Array<T>::Array() : Array{0}
{}

// Constructor template
template <typename T>
Array<T>::Array(std::size_t size) : m_elements {new T[size] {}}, m_size {size}
{}

// Copy constructor template
template <typename T>
Array<T>::Array(const Array& array) : Array{array.m_size}
{
  std::println("Array of {} elements copied", m_size);
  for (std::size_t i {}; i < m_size; ++i)
    m_elements[i] = array.m_elements[i];
}

// Move constructor template
template <typename T>
Array<T>::Array(Array&& moved) /*noexcept*/
  : m_size{moved.m_size}, m_elements{moved.m_elements}
{
  std::println("Array of {} elements moved", m_size);
  moved.m_elements = nullptr; // Otherwise destructor of moved would delete[] m_elements!
}

// Destructor template
template <typename T>
Array<T>::~Array() { delete[] m_elements; }

// const subscript operator template
template <typename T>
const T& Array<T>::operator[](std::size_t index) const
{
  if (index >= m_size)
    throw std::out_of_range {"Index too large: " + std::to_string(index)};
  return m_elements[index];
}

// Non-const subscript operator template in terms of const one
// Uses the 'const-and-back-again' idiom
template <typename T>
T& Array<T>::operator[](std::size_t index)
{
  return const_cast<T&>(std::as_const(*this)[index]);
}

// Template for exception-safe copy assignment operators
// (expressed in terms of copy constructor and swap member)
template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
  Array<T> copy{ rhs }; // Copy...       (could go wrong and throw an exception)
  swap(copy);           // ... and swap! (noexcept)
  return *this;
}

// Move assignment operator template
template <typename T>
Array<T>& Array<T>::operator=(Array&& rhs) /*noexcept*/
{
  std::println("Array of {} elements moved (assignment)", rhs.m_size);

  if (&rhs != this)            // prevent trouble with self-assignments
  {
    delete[] m_elements;       // delete[] all existing elements

    m_elements = rhs.m_elements; // copy the elements pointer and the size
    m_size = rhs.m_size;

    rhs.m_elements = nullptr;  // make sure rhs does not delete[] m_elements
  }
  return *this;                // return lhs
}

// Swap member function template
template <typename T>
void Array<T>::swap(Array& other) noexcept
{
  std::swap(m_elements, other.m_elements); // Swap two pointers
  std::swap(m_size, other.m_size);         // Swap the sizes
}

// Swap non-member function template (optional)
export template <typename T>
void swap(Array<T>& one, Array<T>& other) noexcept
{
  one.swap(other);     // Forward to public member function
}

// push_back() overload for lvalue references
template <typename T>
void Array<T>::push_back(T element)   // Pass by value (copy of lvalue, or moved rvalue!)
{
  Array<T> newArray{m_size + 1};      // Allocate a larger Array<>
  for (std::size_t i{}; i < m_size; ++i)   // Move all existing elements...
    newArray[i] = std::move(m_elements[i]);

  newArray[m_size] = std::move(element); // Move the new one (could itself be a copy already)...

  swap(newArray);                     // ... and swap!
}
