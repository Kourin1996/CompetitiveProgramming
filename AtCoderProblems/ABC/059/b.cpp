#include <iostream>

std::string A;
std::string B;

int main(void){
    std::cin >> A;
    std::cin >> B;

    if( A.length() > B.length() ){
        std::cout << "GREATER" << std::endl;
        return 0;
    }
    if( A.length() < B.length() ){
        std::cout << "LESS" << std::endl;
        return 0;
    }

    int len = A.length();
    for(int i=0; i<len; ++i){
        if( A[i] == B[i] ) continue;
        if( A[i]  > B[i] ){
            std::cout << "GREATER" << std::endl;
            return 0;
        }
        if( A[i]  < B[i] ){
            std::cout << "LESS" << std::endl;
            return 0;
        }
    }
    std::cout << "EQUAL" << std::endl;
    return 0;
}
