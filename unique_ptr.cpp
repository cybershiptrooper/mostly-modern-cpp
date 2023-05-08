#include <iostream>
#include <memory>

using namespace std;

using T = int;
class Something{
    T my_thing;
   
    public:
    Something(T something):my_thing(something){};
    Something():my_thing(0){};
    void set_thing(T something){
        std::cout<<something-my_thing<<"\n";
        my_thing = something;
    };
    T get_thing(){return my_thing;}
};

class generator{
    unique_ptr<Something> something;
    T default_val;
    public:
    generator(T d):something(make_unique<Something>(Something(d))), default_val(d){std::cout<<"ctor "<<something.get()<<"\n";};
    unique_ptr<Something> get_something(){
        if(!something){
            std::cerr<<"Logic error.\n";
        }
        return std::move(something);
    };
    void make_something(){something = make_unique<Something>(default_val); std::cout<<something.get()<<"\n";};
};

void func(generator& g){
    auto thing = g.get_something();
    thing->set_thing(69);
}

int main(int argc, char const *argv[])
{
    generator z(0);
    func(z);
    if(z.get_something()) std::cout<<"ffs\n";
    else{
        z.make_something();
    }
    return 0;
}
