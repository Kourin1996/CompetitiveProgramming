#include <iostream>
int N = 0, K = 0, X = 0, Y = 0;
int main(void){
    std::cin >> N >> K >> X >> Y;
    std::cout << ((N <= K) ? N*X : (K*X + (N-K)*Y)) << std::endl;
}
