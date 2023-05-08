#include <type_traits>
#include <iostream>
#include <variant>
#include <string>

using namespace std;

struct a{const string text = "a";const string text2 = "eea";};
struct b{const string text = "b";const string text2 = "eea";};
struct c{const string text = "c";const string text2 = "eea";};
struct abc{const string text = "abc";const string text2 = "eea";};

using word_type = variant<a, b, c, abc>;
auto tag = [](auto&& arg)->string{return arg.text;};
void func(word_type t){
    string tex = visit(tag, t);
}

int main(int argc, char const *argv[])
{
    int i = 0;
    while(i++ < 100000) func(a());
    return 0;
}
