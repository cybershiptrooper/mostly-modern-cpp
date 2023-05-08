#include <iostream>
#include <string>
using namespace std;

class Printer{
    public:
    template<typename T>
    void process(T t){std::cout<<"Not supported!\n";}

    void process(double d){std::cout<<d<<"\n";}

    void process(string s){std::cout<<"I am "<<s<<"\n";}
};

template<typename Processor>
struct smart_visitor{
    smart_visitor(Processor& p):p(p){};

    template<typename T>
    void operator()(T t){
        p.process(t);
    }
    template<typename T, typename... Rest>
    void operator()(T t, Rest... rest){
        p.process(t);
        (*this)(rest...);
    }
    private:
    Processor& p;
};


template<typename Visitor>
void visit_content(Visitor&& v){  v(1.0, 69.0, 69, string("lucy"), 12, 'a'); };


int main(int argc, char const *argv[])
{
    Printer p;
    smart_visitor<Printer> visitor(p);
    visit_content(visitor);
    return 0;
}
