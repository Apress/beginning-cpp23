// Argument indices for std::println()
import std;

int main()
{
  const double pi{ std::numbers::pi };
  std::println("Default: {0:.2}, fixed: {0:.2f}, scientific: {0:.2e}, general: {0:.2g}", pi);
  std::println("Default: {0}, binary: {0:b}, hex.: {0:x}", 314);
  std::println("Default: {0}, decimal: {0:d}, hex.: {0:x}", 'c');
  std::println("Alternative hex.: {0:#x}, binary: {0:#b}, HEX.: {0:#X}", 314);
  std::println("Forced sign: {0:+}, space sign: {0: }", 314);
  std::println("All together: {0:*<+10.4f}, {1:+#09x}", pi, 314);
}
