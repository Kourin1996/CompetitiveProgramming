#include <iostream>

int X = 0;

int main(void){
    std::cin >> X;
    std::cout << ( X/10 + X%10 ) << std::endl;
}
