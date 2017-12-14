#include <iostream>

int A = 0, B = 0, C = 0, D = 0;

int main(void){
    std::cin >> A >> B >> C >> D;
    double t = 1.*B/A;
    double a = 1.*D/C;

    if(t == a){
        std::cout << "DRAW" << std::endl;
    }else if(t > a){
        std::cout << "TAKAHASHI" << std::endl;
    }else{
        std::cout << "AOKI" << std::endl;
    }
}
