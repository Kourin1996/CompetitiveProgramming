#include <iostream>
int A = 0, B = 0;
int main(void){
    std::cin >> A >> B;
    std::cout << (A+B)%24 << std::endl;
}
