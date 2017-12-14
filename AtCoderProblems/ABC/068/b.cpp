#include <iostream>
#include <cmath>

int N;
int main(void){
    std::cin >> N;
    int l2 = log2(N);
    std::cout << pow(2.0,l2) << std::endl;
}
