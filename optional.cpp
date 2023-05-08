#include <iostream>
#include <string>
#include <optional>
using namespace std;
int main() {
    optional<string> optstr;
    optstr = "Hello";
    std::cout << *optstr << std::endl;
    return 0;
}