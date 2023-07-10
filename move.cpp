// #include <iostream>
// #include <optional>

// template<typename T>
// std::optional<T> movefunc(T param){
//     if(param > 0)
//     {
//         auto moved = std::move(param);
//         moved = 0;
//         return moved;
//     }
//     return std::nullopt;
// }

// template<typename T>
// void print_if_moved(T in){
//     if(auto l = movefunc<T>(std::move(in))){
//         std::cout << in << " " << l.value() << "\n";
//     }
//     else 
//         std::cout << in;
// }

// int main(){
//     print_if_moved(69);
//     print_if_moved(0);

//     return 0;
// }
#include <iostream>
#include <optional>
#include <memory>

template<typename T>
std::optional<T> movefunc(T param){
    if(*param > 0)
    {
        auto moved = std::move(param);
        *moved = 0;
        return moved;
    }
    return std::nullopt;
}

template<typename T>
void print_if_moved(T in){
    if(auto l = movefunc<T>(std::move(in))){
        std::cout << *in << " " << *l.value() << "\n";
    }
    else 
        std::cout << *in;
}

int main(){
    auto sp1 = std::make_shared<int>(69);
    auto sp2 = std::make_shared<int>(0);
    print_if_moved(sp1);
    print_if_moved(sp2);

    return 0;
}