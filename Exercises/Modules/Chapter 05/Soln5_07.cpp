// Exercise 5-7. Outputting product records & cost
// Getting the alignment right is tricky.
// You have to adjust the field widths until it looks OK.
import std;

int main()
{
  std::vector<unsigned> product_id;
  std::vector<unsigned> quantity;
  std::vector<double> unit_cost;

  // Read the records
  while (true)
  {
    std::print("Enter a record - product number, quantity, unit cost separated by spaces: ");
    unsigned id {};
    unsigned n {};
    double cost {};
    std::cin >> id >> n >> cost;

    product_id.push_back(id);
    quantity.push_back(n);
    unit_cost.push_back(cost);
    
    std::print("Do you want to enter another record (Y or N): ");
    char answer {};
    std::cin >> answer;
    if (std::toupper(answer) == 'N') break;
  }
  
  // Column headings
  std::println("{:10} {:10} {:10} {:10}", "Product", "Quantity", "Unit Price", "Cost");
  
  double total_cost {};
  for (std::size_t i {}; i < product_id.size(); ++i)
  {
    const auto cost{ quantity[i] * unit_cost[i] };
    
    std::println("{:<10} {:<10} ${:<9.2f} ${:<9.2f}", product_id[i], quantity[i], unit_cost[i], cost);
    
    total_cost += cost;
  }
  // Note the little trick to add empty space...
  std::println("{:33}${:<9.2f}", "", total_cost);
}