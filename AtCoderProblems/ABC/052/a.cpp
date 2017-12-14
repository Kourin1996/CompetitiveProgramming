#include <iostream>
int A = 0, B = 0, C = 0, D = 0;
int main(void){
    std::cin >> A >> B >> C >> D;
    std::cout << ((A*B > C*D) ? A*B : C*D) << std::endl;
}
