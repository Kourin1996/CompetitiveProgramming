#include <iostream>
#include <algorithm>
int A, B, C, D;
int main(void){
    std::cin >> A >> B >> C >> D;
    std::cout << std::max(0, std::min(B,D) - std::max(A,C)) << std::endl;
}
