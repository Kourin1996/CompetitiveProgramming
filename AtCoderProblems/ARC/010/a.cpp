#include <iostream>
int N = 0, M = 0, A = 0, B = 0;
int c = 0;
int main(void){
    std::cin >> N >> M >> A >> B;
    for(int i=0; i<M; ++i){
        if(N <= A) N += B;
        std::cin >> c;
        N -= c;
        if(N < 0){
            std::cout << i+1 << std::endl;
            break;
        }
    }

    if(N >= 0){
        std::cout << "complete" << std::endl;
    }
}
