#include <iostream>
int A = 0, B = 0;

int main(void){
    std::cin >> A >> B;
    A = (A == 1) ? 14 : A;
    B = (B == 1) ? 14 : B;

    if(A == B){
        std::cout << "Draw" << std::endl;
    }else if(A > B){
        std::cout << "Alice" << std::endl;
    }else{
        std::cout << "Bob" << std::endl;
    }
}

