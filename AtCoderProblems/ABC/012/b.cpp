#include <iostream>
#include <iomanip>
#include <algorithm>
int N = 0;
int main(void){
    std::cin >> N;
    std::cout << std::setfill('0') << std::setw(2) << N / 3600;
    std::cout << ':';
    std::cout << std::setfill('0') << std::setw(2) << (N/60) % 60;
    std::cout << ':';
    std::cout << std::setfill('0') << std::setw(2) << N % 60;
    std::cout << std::endl;
}
