#ifndef FOO_H
#define FOO_H

inline int foo(int x) {
    static int n = 1;

    return x * (n++);
}

struct Foo {
    inline static int foo = 1;
};

#endif  // FOO_H