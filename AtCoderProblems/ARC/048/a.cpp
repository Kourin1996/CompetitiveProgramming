#include <iostream>
#include <cstdlib>

long long int A, B;

int main(void){
    std::cin >> A >> B;

    if(A*B >= 0){
        std::cout << std::abs(A-B) << std::endl;
    }else{
        std::cout << (std::abs(A) + std::abs(B) - 1) << std::endl;
    }
}
