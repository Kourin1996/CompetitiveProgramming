#include <iostream>
#include <vector>

std::vector<int> L(1000);

int N,M;
int main(void){
    while(std::cin >> N >> M){
        if(N == 0 && M == 0) break;
        for(int i=0; i<N; ++i){
            std::cin >> L[i];
        }

        bool f;
        std::vector<int> b(1012);
        for(int S=0; S<(1<<M); ++S){
            int sum = 0;
            for(int i=0; i<M; ++i){
                b[i] = (S>>i&1);
                sum += b[i];
            }

            for(int i=0; i<N-1; ++i){
                b[M+i] = L[i+1] - L[i] + b[i];
            }

            f = (sum == L[0]);
            for(int i=0; i<N+M-1; ++i){
                if(b[i] != 0 && b[i] != 1){
                    f = false;
                }
            }
            if(f){
                break;
            }
        }

        if(f){
            for(int i=0; i<N+M-1; ++i){
                std::cout << b[i];
            }
            std::cout << std::endl;
        }else{
            std::cout << "Goofy" << std::endl;
        }
    }
}
