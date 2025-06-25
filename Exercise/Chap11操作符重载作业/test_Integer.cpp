#include "Integer.hpp"
#include <iostream>

int main() {
    //constructor test
    Integer a(100);
    Integer b("200");
    char test[10]="365";
    Integer t(test);
    std::cout << "a " << a << ", b " << b << ", t "<<t<<std::endl;

    //copy test
    Integer n(a);
    std::cout<<"n "<<n<<std::endl;
    Integer nn;
    std::cout<<"When nn is construted by default, nn  "<<nn<<std::endl;
    nn=n;
    std::cout<<"After copy assignment, nn  "<<nn<<std::endl;
    nn=123;
    std::cout<<"After copy assignment(not the 'copy' version), nn  "<<nn<<std::endl;

    //Relational operator & Arithmetic operator
    Integer c = a + b;
    std::cout << "c = a + b " << c << std::endl;

    if(c>a){
        std::cout<<"c > a"<<std::endl;
    }
    else
    {
        std::cout<<"c <= a"<<std::endl;
    }

    Integer ne(-250);
    std::cout<<"ne "<<ne<<" initially"<<std::endl;
    std::cout<<"if you want a positive,now ne "<< +ne <<std::endl;
    std::cout<<"but ne itself "<<ne<<std::endl;

    c += 50;
    std::cout << "c += 50, c " << c << std::endl;

    if (a < b) {
        std::cout << "a < b" << std::endl;
    }
    //input output
    Integer x;
    std::cin >> x;
    Integer y(x);
    std::cout << "y = " << y << std::endl;

    return 0;
}