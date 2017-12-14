#include <iostream>

std::string O;
std::string E;

int main(void){
    std::cin >> O;
    std::cin >> E;

    auto ito = O.begin(), endo = O.end();
    auto ite = E.begin(), ende = E.end();

    while( ito != endo || ite != ende ){
        if( ito != endo ){
            std::cout << *ito;
            ito++;
        }
        if( ite != ende ){
            std::cout << *ite;
            ite++;
        }
    }
    std::cout << std::endl;
}
