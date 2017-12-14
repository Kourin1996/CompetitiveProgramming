#include <iostream>

std::string N;

int main(void){
    std::cin >> N;
    std::cout << ((N[0] == N[1] && N[1] == N[2] && N[2] == N[3]) ? "SAME" : "DIFFERENT") << std::endl;
}
