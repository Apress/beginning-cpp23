// Using smart pointers
import std;

int main()
{
  std::vector<std::shared_ptr<std::vector<double>>> records; // Temperature records by days

  for (int day{ 1 };; ++day)       // Collect temperatures by day
  {
    // Vector to store current day's temperatures created in the free store
    auto day_records{ std::make_shared<std::vector<double>>() };
    records.push_back(day_records); // Save pointer in records vector

    std::print("Enter the temperatures for day {} separated by spaces. ", day);
    std::println("Enter 1000 to end:");

    while (true)
    { // Get temperatures for current day
      double t{};      // A temperature
      std::cin >> t;
      if (t == 1000.0) break;

      day_records->push_back(t);
    }

    std::print("Enter another day's temperatures (Y or N)? ");
    char answer{};
    std::cin >> answer;
    if (std::toupper(answer) != 'Y') break;
  }

  for (int day{ 1 }; auto record : records)
  {
    double total{};
    std::size_t count{};

    std::println("\nTemperatures for day {}:", day++);
    for (auto temp : *record)
    {
      total += temp;
      std::print("{:6.2f}", temp);
      if (++count % 5 == 0) std::println("");
    }

    std::println("\nAverage temperature: {:.2f}", total / count);
  }
}
