export module words;

import std;

export namespace words
{
  using Words = std::vector<std::shared_ptr<std::string>>;

  void sort(Words& words);
  void extract_words(Words& words, const std::string& text, const std::string& separators);
  void print_words(const Words& words);
}