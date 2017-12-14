#include <iostream>
int A = 0, B = 0, C = 0, D = 0;
int main(void){
    std::cin >> A >> B >> C >> D;

    B *= C;
    D *= A;

    if(B == D){
        std::cout << "DRAW" << std::endl;
    }else if(B > D){
        std::cout << "TAKAHASHI" << std::endl;
    }else{
        std::cout << "AOKI" << std::endl;
    }
}
