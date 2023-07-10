#include <iostream>
#include <functional>

using namespace std;

class A {
    public:
    void public_function(int b) {
        auto f = bind(&A::pvt_function, this, 69, placeholders::_1);
        f(b);
    }

    private:
    void pvt_function(int a, int b) {
        cout << "a: " << a << " b: " << b << endl;
    }
};

int main() {
    A a;
    a.public_function(420);
    return 0;
}