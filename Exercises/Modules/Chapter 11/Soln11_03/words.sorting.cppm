export module words.sorting;

import std;

export namespace words
{
  using Words = std::vector<std::shared_ptr<std::string>>;

  namespace sorting
  {
    void sort(Words& words);
  }
}