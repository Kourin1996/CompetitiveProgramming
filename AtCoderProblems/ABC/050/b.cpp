#include <iostream>
#include <vector>

int N = 0;
std::vector<int> T;
int M = 0;

int main(void){
    int i, sum = 0;
    std::cin >> N;
    T.resize(N);
    for(i=0; i<N; ++i){
        std::cin >> T[i];
        sum += T[i];
    }
    std::cin >> M;

    int P = 0, X = 0;
    for(i=0; i<M; ++i){
        std::cin >> P >> X;
        std::cout << (sum-T[P-1]) + X << std::endl;
    }
}
