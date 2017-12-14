#include <iostream>
int A,B,C;
int main(void){
    std::cin >> A >> B >> C;
    if(A<=C && C<=B){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
}
