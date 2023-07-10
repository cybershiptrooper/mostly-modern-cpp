#include <iostream>
#include <functional>

using namespace std;

class A {
    public:
    void public_function(int b, bool type2=false) {
        auto f_1 = std::function<void(int)>(bind(&A::pvt_function, this, 69, placeholders::_1));
        auto f_2 = std::function<void(int)>(bind(&A::pvt_function_2, this, 69, placeholders::_1, 69420));

        auto f = type2 ? f_2 : f_1;
        f(b);
    }

    private:
    void pvt_function(int a, int b) {
        cout << "a: " << a << " b: " << b << endl;
    }

    void pvt_function_2(int a, int b, int c) {
        cout << "a: " << a << " b: " << b << " c: " << c << endl;
    }
};

int main() {
    A a;
    a.public_function(420);
    a.public_function(420, true);
    return 0;
}