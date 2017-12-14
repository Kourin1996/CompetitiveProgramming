#include <iostream>

int N = 0;

int main(void){
    std::cin >> N;
    std::cout << ( (N%2 == 0) ? "Blue" : "Red" ) << std::endl;
}
