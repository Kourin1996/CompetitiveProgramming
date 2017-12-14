#include <iostream>
#include <cmath>
#include <cassert>
long long int A, K;
const long long int INF = 2000000000000;
int main(void){
    std::cin >> A >> K;
    if(K == 0){
        std::cout << INF - A << std::endl;
    }else{
        long long int n = 0;
        while( A < INF){
            ++n;
            A += 1 + K*A;
        }
        std::cout << n << std::endl;
    }
}
