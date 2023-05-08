#include <iostream>
#include <variant>
#include <string>
using namespace std;


struct a{const string text = "a";const string text2 = "eea";};
struct b{const string text = "b";const string text2 = "eea";};
struct c{const string text = "c";const string text2 = "eea";};
struct abc{const string text = "abc";const string text2 = "eea";};

using word_type = variant<a, b, c, abc>;

template <class, class>
constexpr bool is_one_of_variants_types = false;

template <class... Ts, class T>
constexpr bool is_one_of_variants_types<std::variant<Ts...>, T> = (std::is_same_v<T, Ts> || ...);

template<class T>
auto func() -> std::enable_if_t<is_one_of_variants_types<word_type, T>>
{
    std::cout<< T().text<<"\n";
}

int main(int argc, char const *argv[])
{
    func<a>();
    return 0;
}
