export module words:alias;

import std;

namespace words
{
  export using Words = std::vector<std::shared_ptr<std::string>>;
}