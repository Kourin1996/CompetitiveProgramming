#include <iostream>
#include <string>
int N;
int main(void){
    std::cin >> N;
    int l  = (N-1)/9+1;
    char c = (N%9) ? (N%9+'0') : '9';
    std::string str = std::string(l, c);
    std::cout << str << std::endl;
}
