export module words;

import std;

export namespace words
{
  using Words = std::vector<std::shared_ptr<std::string>>;

  void sort(Words& words);
  void extract_words(Words& words, const std::string& text, const std::string& separators);
  void print_words(const Words& words);
}

// Technique 1: export a namespace alias
export namespace w = words;

// Technique 2: export a using namespace directive
namespace wrds
{
  export using namespace words;
}
