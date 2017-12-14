#include <iostream>
#include <vector>

int N, Q;
std::vector<long long int> a;

int main(void){
    std::cin >> N >> Q;
    a.resize(N, 0);

    for(int i=0; i<Q; ++i){
        int L, R, T;
        std::cin >> L >> R >> T;
        for(int j=L-1; j<R; ++j){
            a[j] = T;
        }
    }

    for(int i=0; i<N; ++i){
        std::cout << a[i] << std::endl;
    }
}
