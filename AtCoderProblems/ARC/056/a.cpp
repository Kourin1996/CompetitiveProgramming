#include <iostream>
#include <algorithm>
long long int A, B, K, L;
int main(void){
    std::cin >> A >> B >> K >> L;
    std::cout << std::min( (K/L)*B+(K%L)*A, ((K+L-1)/L)*B ) << std::endl;
}
