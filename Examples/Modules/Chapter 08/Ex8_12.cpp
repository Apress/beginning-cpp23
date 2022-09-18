// Program that lists its command line arguments
import <print>;

int  main(int argc, char* argv[])
{
  for (int i{}; i < argc; ++i)
    std::println("{}", argv[i]);
}
