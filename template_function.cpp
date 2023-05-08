#include <iostream>

template <class Function>
int apply(int a, const Function& processor){
    return processor(a);
}

int main() {
    int a = 90;
    std::cout << apply(10, [&a](int x) {a+=x; return x;}) << " " << a ;
    return 0;
}