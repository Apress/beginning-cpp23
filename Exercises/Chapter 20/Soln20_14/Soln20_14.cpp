// Exercise 20-14: unseen views, structured bindings, and std::ranges::to<>
import std;

int main()
{
  using namespace std::views;
  
  // Create the containers once using a std::from_range constructor...
  std::vector v(std::from_range, 
      iota(0)
        | transform([](int i) { return i * 3; }) 
        | drop_while([](int i) { return i < 5; })   // Or: filter([](int i) { return i > 5; })
        | take_while([](int i) { return i < 50; })
  );

  // ... and once using std::ranges::to<> (or the other way around, of course...)
  auto map = zip(v, repeat(std::string("zip zip"))) 
           | std::ranges::to<std::map<int, std::string>>();

  // Once using a structured binding...
  for (auto& [key, value] : map)
  {
    value = "zap zap";
  }

  // ... and once using the std::views::values() view
  for (auto& value : values(map))
  {
    value = "zop zop";
  }
}