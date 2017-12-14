#include <iostream>
std::string N;
int main(void){
    std::cin >> N;
    std::cout << ( (N[0] == '9' || N[1] == '9') ? "Yes" : "No" ) << std::endl;
}
