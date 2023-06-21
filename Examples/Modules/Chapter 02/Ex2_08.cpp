// Formatting numeric values with std::println() 
import std;

int main()
{
  const double pi{ std::numbers::pi };
  std::println("Default: {:.2}, fixed: {:.2f}, scientific: {:.2e}, general: {:.2g}", 
               pi, pi, pi, pi);
  std::println("Default: {}, binary: {:b}, hex.: {:x}", 314, 314, 314);
  std::println("Default: {}, decimal: {:d}, hex.: {:x}", 'c', 'c', 'c');
  std::println("Alternative hex.: {:#x}, binary: {:#b}, HEX.: {:#X}", 314, 314, 314);
  std::println("Forced sign: {:+}, space sign: {: }", 314, 314);
  std::println("All together: {:*<+10.4f}, {:+#09x}", pi, 314);
}