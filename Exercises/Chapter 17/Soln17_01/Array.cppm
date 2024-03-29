// Same as Ex17_01A, but with a push_back() member and a default constructor
export module array;

import std;

export template <typename T>
class Array
{
public:
  Array();                             // Default constructor
  explicit Array(std::size_t size);    // Constructor
  ~Array();                            // Destructor
  Array(const Array& array);           // Copy constructor
  Array& operator=(const Array& rhs);  // Copy assignment operator
  void swap(Array& other) noexcept;    // Swap member function
  T& operator[](std::size_t index);    // Subscript operator
  const T& operator[](std::size_t index) const; // Subscript operator-const arrays
  void push_back(const T& element);    // Function to add new element to the end
  std::size_t getSize() const noexcept { return m_size; } // Accessor for m_size

private:
  T* m_elements;      // Array of type T
  std::size_t m_size; // Number of array elements
};

// Swap non-member function template
export template <typename T>
void swap(Array<T>& one, Array<T>& other) noexcept
{
  one.swap(other);     // Forward to public member function
}


// Forwarding default constructor template
template <typename T>
Array<T>::Array() : Array{0}
{}

// Constructor template
template <typename T>
Array<T>::Array(std::size_t size) : m_elements{ new T[size] {} }, m_size{ size }
{}

// Copy constructor template
template <typename T>
Array<T>::Array(const Array& array) : Array{array.m_size}
{
  for (std::size_t i {}; i < m_size; ++i)
    m_elements[i] = array.m_elements[i];
}

// Destructor template
template <typename T>
Array<T>::~Array() { delete[] m_elements; }

// const subscript operator template
template <typename T>
const T& Array<T>::operator[](std::size_t index) const
{
  if (index >= m_size)
    throw std::out_of_range{ "Index too large: " + std::to_string(index) };
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

// Template for functions that add new element to the end of the array
// Uses the 'copy-and-swap' idiom.
// If either the Array<> constructor throws
// (std::bad_alloc or some exception from T's default constructor) 
// or any of the copy assignments of a T element throw,
// then the original Array<> remains untouched.
template <typename T>
void Array<T>::push_back(const T& newElement)
{
  Array<T> copy{ m_size + 1 };        // Copy...
  for (std::size_t i {}; i < m_size; ++i)
    copy[i] = m_elements[i];

  copy[m_size] = newElement;          // ... modify ...

  swap(copy);                         // ... and swap!  (noexcept)
}

// Swap member function template
template <typename T>
void Array<T>::swap(Array& other) noexcept
{
  std::swap(m_elements, other.m_elements); // Swap two pointers
  std::swap(m_size, other.m_size);         // Swap the sizes
}