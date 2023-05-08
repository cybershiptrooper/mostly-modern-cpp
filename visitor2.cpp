#include <type_traits>
#include <iostream>
#include <variant>
#include <string>

using namespace std;

struct a{};
struct b{};
struct c{};
struct abc{};

using word_type = variant<a, b, c, abc>;
template<class... Ts> struct overloaded : Ts...
{
    using Ts::operator()...;
};
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;
auto tag = overloaded{
    [](a){return "a";},
    [](b){return "b";},
    [](c){return "c";},
    [](abc){return "abc";}
};

void func(word_type t){
    string tex = visit(tag, t);
}

int main(int argc, char const *argv[])
{
    int i = 0;
    while(i++ < 100000) func(a());
    return 0;
}
