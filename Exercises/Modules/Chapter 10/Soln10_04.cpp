// Your very own interpretation of std::size()
import std;

// Look ma, no sizeof()!
template <typename T, std::size_t N>
size_t my_size([[maybe_unused]] const T (&array)[N]) { return N; }

// Overload with two other templates for std::vector<> and array<> 
template <typename T>
size_t my_size(const std::vector<T>& vector) { return vector.size(); }

template <typename T, std::size_t N>
size_t my_size([[maybe_unused]] const std::array<T,N>& array) { return N; }  // or array.size();

// Note: the [[maybe_unused]] annotations silence compiler warnings 
// about the array parameter not being used in the function body...

/*
Instead of the latter two templates, you can create one template that would make my_size 
accept any argument and call size() on it. This will make it work
for std::array<> and std::vector<>, as well as std::string and many other containers:

template <typename Collection>
size_t my_size(const Collection& collection) { return collection.size(); }

Potential downside is that this will instantiate for int and double type arguments
as well, which may result in somewhat verbose compiler errors.
This issue can be fixed using a requires clause (see Chapter 21).

template <typename Collection> requires requires (const Collection c) { c.size(); }
size_t my_size(const Collection& collection) { return collection.size(); }
*/

int main()
{
  int array[] {4, 8, 15, 16, 23, 42};
  std::println("Size of numbers is {}", my_size(array));
  
  // A string literal is also an array:
  std::println("Size of a very important life lesson is {}",
                    my_size("Always wear a smile. One size fits all."));
  
  std::vector<int> vector{4, 8, 15, 16, 23, 42};
  std::println("Size of vector is {}", my_size(vector));
  
  std::array<int, 6> array_object{4, 8, 15, 16, 23, 42};
  std::println("Size of array_object is {}", my_size(array_object));
}