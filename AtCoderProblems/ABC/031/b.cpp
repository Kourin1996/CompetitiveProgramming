#include <iostream>

int L = 0, H = 0;
int N = 0;
int main(void){
    std::cin >> L >> H;
    std::cin >> N;

    int A = 0;
    for(int i=0; i<N; ++i){
        std::cin >> A;
        std::cout << ( (A < L ) ? (L-A)
                      :(A <= H) ? 0
                      :           -1 )
                  << std::endl;
    }
}
