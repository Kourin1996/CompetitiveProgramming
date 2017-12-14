#include <iostream>
#include <algorithm>

int A = 0, D = 0;

int main(void){
    std::cin >> A >> D;
    std::cout << std::max((A+1)*D, A*(D+1)) << std::endl;
}
