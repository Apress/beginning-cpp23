// Less.cppm - A basic class of functor objects
export module less;

export class Less
{
public:
#ifdef __cpp_static_call_operator   // Not all compilers support static operators yet
  static bool operator()(int a, int b) { return a < b; }
#else
  bool operator()(int a, int b) const { return a < b; }
#endif
};

