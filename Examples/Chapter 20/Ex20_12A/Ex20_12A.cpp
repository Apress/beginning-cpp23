// Finding boxes, this time using range-based algorithms.
import std;
import box;      // From Ex13_03

int main()
{
  std::vector boxes{ Box{1,2,3}, Box{5,2,3}, Box{9,2,1}, Box{3,2,1} };

  // Define a lambda functor to print the result of find() or find_if():
  auto print_result{ [&boxes](auto result)
  {
    if (result == end(boxes))
      std::println("No box found.");
    else
      std::println("Found matching box at position {}", result - begin(boxes));
  } };

  // Find an exact box
  Box box_to_find{ 3,2,1 };
  auto result{ std::ranges::find(boxes, box_to_find) };
  print_result(result);

  // Find a box with a volume larger than that of box_to_find
  const auto required_volume{ box_to_find.volume() };
  result = std::ranges::find_if(boxes,
              [required_volume](const Box& box) { return box > required_volume; });
  print_result(result);
}
