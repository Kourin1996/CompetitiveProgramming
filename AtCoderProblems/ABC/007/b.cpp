#include <iostream>
std::string A;
int main(void){
    std::cin >> A;
    std::cout << (  A.length() > 1 ? A.substr(0, A.length()-1)
                  : A[0] > 'a'     ? ( std::string() + (char)(A[0]-1) )
                  :                 "-1") << std::endl;
}
