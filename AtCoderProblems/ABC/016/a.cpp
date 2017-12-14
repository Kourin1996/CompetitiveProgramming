#include <iostream>
int M = 0, D = 0;
int main(void){
    std::cin >> M >> D;
    std::cout <<  ((M%D == 0) ? "YES" : "NO") << std::endl;
}
