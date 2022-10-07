#include<iostream>

template <typename t>
class foo{
    public:
    t var;
    foo(t x):var(x){}

};


class derived: public foo<std::string>{};

int main(){
     derived d;    
return 0;
}
