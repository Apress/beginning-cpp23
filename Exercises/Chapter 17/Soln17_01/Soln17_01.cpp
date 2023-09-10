// Adding a push_back() member function and a default constructor to the Array<> 
// class template. Using copy-and-swap for a exception-safe push_back().
import array;
import std;

int main()
{
  const unsigned numElements{ 100 };

  Array<unsigned> squares;       // default construction
  for (unsigned i {}; i < numElements; ++i)
	  squares.push_back(i * i);  // push_back()

  std::println("{} squares were added.", squares.getSize());
  std::println("For instance: 13 squared equals {}", squares[13]);
}