#include <iostream>
int N = 0;
int main(void){
    std::cin >> N;
    std::cout << '1' << std::string(N-1, '0') << '7' << std::endl;
}
