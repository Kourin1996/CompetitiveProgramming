#include <iostream>
int main(void){
    std::string S;
    std::cin >> S;
    S[S.length()-1] = '5';
    std::cout << S << std::endl;
}
