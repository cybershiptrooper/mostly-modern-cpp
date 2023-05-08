#include <iostream>

using namespace std;
void func(const char* in){
    cout<<in<<"\n";
}
int main(int argc, char const *argv[])
{
    const char key[] = "BT";
    func(key);
    return 0;
}
