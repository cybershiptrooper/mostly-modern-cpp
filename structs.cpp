#include <iostream>

struct pair{
    int x, y;
    pair(int x, int y):x(x), y(y){}
};

int main(int argc, char const *argv[])
{
    pair a(10, 13); 
    // a.x = 10;
    pair b = a;
    std::cout << b.x <<"\n";
    return 0;
}
