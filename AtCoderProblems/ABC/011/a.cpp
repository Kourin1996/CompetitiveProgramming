#include <iostream>
#include <algorithm>
int N = 0;
int main(void){
    std::cin >> N;
    std::cout << std::max(1,(N+1)%13) << std::endl;
}
