#include <vector>
#include <tuple>
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
struct viggywiggy {
    int a;
};
using duo = tuple<viggywiggy, string>;

int main() {
    stack<duo> v;
    // v.emplace(NULL, NULL);
    // cout << std::get<string>(v.top()) << endl;
    v.emplace(viggywiggy{1}, "one");
    v.emplace(viggywiggy{2}, "two");
    v.emplace(viggywiggy{3}, "three");

    while (v.empty() == false) {
        auto [i, s] = v.top();
        cout << i.a << " " << s << endl;
        v.pop();
    }
    return 0;
}