#include <iostream>
std::string A, B, C;
int main(void){
    std::cin >> A >> B >> C;
    std::cout << ((A[A.length()-1] == B[0] && B[B.length()-1] == C[0]) ? "YES" : "NO") << std::endl;
}
