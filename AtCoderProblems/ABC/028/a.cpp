#include <iostream>

int N = 0;

int main(void){
    std::cin >> N;
    if(N <= 59){
        std::cout << "Bad";
    }else if(N <= 89){
        std::cout << "Good";
    }else if(N <= 99){
        std::cout << "Great";
    }else{
        std::cout << "Perfect";
    }
    std::cout << std::endl;
}
