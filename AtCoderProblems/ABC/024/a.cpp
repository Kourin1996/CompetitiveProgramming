#include <iostream>

int A = 0, B = 0, C = 0, K = 0;
int S = 0, T = 0;

int main(void){
    std::cin >> A >> B >> C >> K;
    std::cin >> S >> T;

    std::cout << (((S+T) >= K) ? ((A-C)*S +(B-C)*T) : (A*S + B*T)) << std::endl;
}
