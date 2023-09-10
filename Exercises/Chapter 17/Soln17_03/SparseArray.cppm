// SparseArray class template definition
// Note the use of the find() helper function and the const-and-back-again idiom to minimize code duplication

export module sparse_array;

import std;

export template<typename T>
class SparseArray
{
public:
  T& operator[](std::size_t index);     // Subscript operator (creates default-constructed value if no value exists for the given index)
  T& at(std::size_t index);             // Access function (throws std::out_of_range if no value exists for the given index)
  const T& at(std::size_t index) const; // const overload of at()
  bool elementExistsAt(std::size_t index) const;  // Return true iff an element exists at the given index

private:
  T* find(std::size_t index);           // Helper function (returns nullptr if no value exists for the given index)
  const T* find(std::size_t index) const;
  
  std::vector<std::pair<std::size_t, T>> m_values;
};

template<typename T>
T& SparseArray<T>::operator[](std::size_t index)
{
  if (auto* found{ find(index) }; found) // Using C++17 initialization statements for if statement 
  {                                      // (see at() function for the more traditional equivalent)
	  return *found;
  }
  else
  {
    m_values.push_back({ index, T{} });  // Alternatives: push_back(std::pair{...}), push_back(std::pair<std::size_t, T>{...}), push_back(std::make_pair(...))
    return m_values.back().second;       // Remember: std::vector<>::back() returns a reference to its last element
  }
}

template<typename T>
const T& SparseArray<T>::at(std::size_t index) const
{
  const auto* found{ find(index) };
  if (found)
  {
	  return *found;
  }
  else
  {
    throw std::out_of_range{"No value exists at index " + std::to_string(index)};
  }
}

template<typename T>
T& SparseArray<T>::at(std::size_t index)
{
  return const_cast<T&>(std::as_const(*this).at(index));
}

template<typename T>
bool SparseArray<T>::elementExistsAt(std::size_t index) const
{
  return find(index) != nullptr;
}

template<typename T>
const T* SparseArray<T>::find(std::size_t index) const
{
  for (auto& pair : m_values)
  {
    if (pair.first == index)
      return &pair.second;
  }
  return nullptr;
}

template<typename T>
T* SparseArray<T>::find(std::size_t index)
{
  return const_cast<T*>(std::as_const(*this).find(index));
}
