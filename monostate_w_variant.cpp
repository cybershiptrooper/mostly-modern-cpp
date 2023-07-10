#include <iostream>
#include <variant>

using namespace std;
template<class... Ts>
struct overloaded;

template<class T, class... Ts> 
struct overloaded<T, Ts...> : T, overloaded<Ts...>
{
    overloaded(T t, Ts... ts) : T(t), overloaded<Ts...>(ts...) {}
    using T::operator();
    using overloaded<Ts...>::operator();
};

template<typename T>
struct overloaded<T> : T
{
    overloaded(T t) : T(t) {}
    using T::operator();
};

template<typename... Ts>
auto make_visitor(Ts... ts)
{
    return overloaded<Ts...>(ts...);
}

int main(){
    auto visitor = make_visitor(
        [](int i){cout << "int: " << i << endl;},
        [](double d){cout << "double: " << d << endl;},
        [](monostate){cout << "monostate" << endl;}
    );
    const variant<int, double, monostate>  v = 12;
    visit(visitor, v);
    const variant<int, double, monostate>  v1 = 12.2;
    visit(visitor, v1);
    const variant<int, double, monostate>  v2 = monostate{};
    visit(visitor, v2);
    return 0;
}