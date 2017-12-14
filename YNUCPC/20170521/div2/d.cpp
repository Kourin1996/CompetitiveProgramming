#include <iostream>
#include <cmath>

int a = 0, b = 0;

int digit(int n){
    return log10(n)+1;
}

int main(void){
    while(std::cin >> a >> b){
        std::cout << digit(a+b) << std::endl;
    }
}
