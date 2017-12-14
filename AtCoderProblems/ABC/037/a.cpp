#include <iostream>
#include <algorithm>

int A = 0, B = 0, C = 0;

int main(void){
    std::cin >> A >> B >> C;
    std::cout << C/std::min(A,B) << std::endl;
}

