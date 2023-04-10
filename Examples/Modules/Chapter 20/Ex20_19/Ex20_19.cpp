// Converting ranges to containers
import std;

import <random>;

bool isOdd(int i) { return i % 2 == 1; }

int main()
{
  auto view = std::views::iota(1, 10); // Could be any view/range...

  // std::ranges::to<>() range conversion:
  auto deque = std::ranges::to<std::deque<int>>(view); // Any container
  auto vector = std::ranges::to<std::vector>(view);    // Deducing type
  auto set = deque | std::ranges::to<std::unordered_set>(); // Pipe syntax
  auto longs = set | std::ranges::to<std::vector<long>>();  // Type conversion

  // Constructors with std::from_range tag:
  std::vector v{ std::from_range, set | std::views::filter(isOdd) };
  
  // xxx_range() members:
  std::vector<int> v1;
  v1.assign_range(view | std::views::reverse); // Assign 9, 8, 7, ..., 1
  v1.append_range(std::views::repeat(-1, 3));  // Append 3 times -1
  v1.insert_range(v1.begin(), set);            // Insert any range
  
  // Pre-C++23: iterator-pair based (same as before)
  auto odds = set | std::views::filter(isOdd);
  std::vector<int> v2{ odds.begin(), odds.end() };
  
  std::vector<int> v3;
  const auto atoi = view | std::views::reverse;
  v3.assign(atoi.begin(), atoi.end());
  const auto repeated = std::views::repeat(-1, 3);
  v3.insert(v3.end(), repeated.begin(), repeated.end());  // No append()!
  v3.insert(v3.begin(), set.begin(), set.end());
}
