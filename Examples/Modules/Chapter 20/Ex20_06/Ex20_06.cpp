// Creating and working with Standard iterators
import std;

int main()
{
  std::vector letters{ 'a', 'b', 'c', 'd', 'e' };
  auto my_iter{ letters.begin() };

  std::println("{}", *my_iter);       // a

  *my_iter = 'x';
  std::println("{}", letters[0]);     // x

  ++my_iter;                          // Move my_iter to the next element
  std::println("{}", *my_iter);       // b
  
  my_iter += 2;                       // Move my_iter two elements further
  std::println("{}", *my_iter--);     // d
  std::println("{}", *my_iter);       // c (iterator altered using the post-decrement
                                      //    operator in the previous statement)
  auto copy{ my_iter };               // Create a copy of my_iter (pointing at c)
  my_iter += 2;                       // Move my_iter two elements further
  std::println("{}", *copy);          // c (copy not affected by moving my_iter)
  std::println("{}", *my_iter);       // e
  std::println("{}", my_iter - copy); // 2
}
