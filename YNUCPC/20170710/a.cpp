#include <iostream>
#include <algorithm>
int A, B, C;
int main(void){
    std::cin >> A >> B >> C;
    std::cout << C/std::min(A,B) << std::endl;
}
