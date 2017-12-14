#include <iostream>
int N = 0;
int main(void){
    std::cin >> N;
    std::cout << (N <= 59 ? "Bad"
                 :N <= 89 ? "Good"
                 :N <= 99 ? "Great"
                 :          "Perfect") << std::endl;
}
