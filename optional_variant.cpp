#include <iostream>
#include <optional>
#include <variant>
#include <string>
using namespace std;

using type = variant<string, int>;

template<typename T, typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::variant<T, Ts...>& v)
{
    std::visit([&os](auto&& arg) {
        os << arg;
    }, v);
    return os;
}

void deal_with_type(optional<type> t){
    cout << t.value_or("false") << endl;
}

int main() {
    optional<type> t1 = "hello";
    optional<type> t2 = 1;
    deal_with_type(t1);
    deal_with_type(t2);
    return 0;
}