#include <iostream>
#include <string>
#include "Money.hpp"

int main(){
    Money a {'1','2','8','6','8','3','5'};
    std::cout << "a = ";
    a.print();

    Money b{'1','1','1'};
    std::cout << "b = ";
    b.print();

    Money c(a.add(b));
    std::cout << "c = a + b = ";
    c.print();

    Money d {"0005"};
    std::cout << "d = ";
    d.print();

    try{
        d.remove(b);
        std::cout << "d - b = ";
        d.print();

    } catch( std::exception &ex){
        std::cerr << "exception:" << ex.what() << std::endl;
    }
}