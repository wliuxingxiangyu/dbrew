#include <string.h>
#include <spec.h>
// #include "spec.c"

typedef int (*f_t)(char*);

int isHello(char* s)
{
  return strcmp(s, "Hello");
}

int main(int argc, char* argv[])
{
    // force relocation of strcmp
    if (strcmp("Foo", argv[0])==0) return 0;

    brew_def_verbose(True, True, True);
    f_t f = (f_t) brew_rewrite((uint64_t) isHello, "Bla");

    return f(argv[1]);
}
