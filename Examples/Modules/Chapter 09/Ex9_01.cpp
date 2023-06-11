// Working with std::optional<>
import std;

std::optional<std::size_t> find_last(
   const std::string& string, char to_find,
   std::optional<std::size_t> start_index = std::nullopt); // or: ... start_index = {});

int main()
{
  const auto string{ "Growing old is mandatory; growing up is optional." };

  const std::optional<std::size_t> found_a{ find_last(string, 'a') };
  if (found_a)
    std::println("Found the last a at index {}", *found_a);

  const auto found_b{ find_last(string, 'b') };
  if (found_b.has_value())
    std::println("Found the last b at index {}", found_b.value());

// Following line gives an error (cannot convert optional<size_t> to size_t)
// const std::size_t found_c{ find_last(string, 'c') }; 
                                                   
  const auto found_early_i{ find_last(string, 'i', 10) };
  if (found_early_i != std::nullopt)
    std::println("Found an early i at index {}", *found_early_i);
}

std::optional<std::size_t> find_last(
  const std::string& string, char to_find, std::optional<std::size_t> start_index
)
{
  // code below will not work for empty strings  
  if (string.empty())            
    return std::nullopt;     // or: 'return std::optional<std::size_t>{};'
                             // or: 'return {};'
  // determine the starting index for the loop that follows:
  std::size_t index{ start_index.value_or(string.size() - 1) };

  while (true)  // never use while (index >= 0) here, as size_t is always >= 0!
  {
    if (string[index] == to_find) return index;
    if (index == 0) return std::nullopt;
    --index;
  }
}
