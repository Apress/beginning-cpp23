import std;

#define DEFINE_PRINT_FUNC\
TION(NAME, COUNT, VALUE) v\
oid NAME##COUNT() { std::pr\
intln(#VALUE); }

DEFINE_PRINT_FUNCTION(fun, 123, Test 1 "2" 3)

\
i\
nt\
 ma\
in()\
{fun1\
23();}\
