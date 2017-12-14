#include <iostream>
#include <cmath>
long long int N = 0, K = 0;
int main(void){
    std::cin >> N >> K;
    std::cout << (int)(K*pow(K-1,N-1)) << std::endl;
}
