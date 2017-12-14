#include <iostream>
std::string A, B;
int main(void){
    std::cin >> A >> B;
    std::cout << ((A.length() > B.length()) ? A : B) << std::endl;
}
