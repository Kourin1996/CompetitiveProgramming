#include <iostream>
#include <cstdlib>

int A = 0, B = 0;

int main(void){
    std::cin >> A >> B;
    A = abs(A);
    B = abs(B);
    std::cout << (( A == B ) ? "Draw" :
                  ( A >  B ) ? "Bug"  :
                               "Ant" ) << std::endl;
}
