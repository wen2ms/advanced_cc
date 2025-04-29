// #include "foo.h"

// This variable or function exists somewhere else — I'm just declaring it here.
extern void func();

extern int bar;

// only definitions are allowed at global scope.
// bar = 10;

void test() {
    bar = 10;
}