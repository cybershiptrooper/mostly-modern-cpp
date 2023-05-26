#include <iostream>
#include <type_traits>

struct A {};

struct B {};

template<typename T,
         typename = typename std::enable_if<std::is_same<T, A>::value>::type>
void add(int i);

template<typename T,
         typename = typename std::enable_if<std::is_same<T, B>::value>::type>
void add(int i, bool val);

template<typename T, typename>
void add(int i) {
    std::cout << "add<A>(" << i << ")" << std::endl;
}

template<typename T, typename>
void add(int i, bool val) {
    std::cout << "add<B>(" << i << ", " << val << ")" << std::endl;
}

int main() {
    add<A>(1);
    add<B>(2, true);
}