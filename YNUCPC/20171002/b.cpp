#include <iostream>
std::string A;
long long B;
int main(void){
    std::cin >> A;
    std::cin >> B;
    int len = A.length();
    std::cout << A[(B-1)%len] << std::endl;
}
