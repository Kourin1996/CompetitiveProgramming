#include <iostream>

int L, H;
int N;

int main(void){
    int A;
    std::cin >> L >> H;
    std::cin >> N;

    for(int i=0; i<N; ++i){
        std::cin >> A;
        if(A < L){
            std::cout << L-A << std::endl;
        }else if(A > H){
            std::cout << -1 << std::endl;
        }else{
            std::cout << 0 << std::endl;
        }
    }


}
