#include <iostream>
#include <vector>

int N = 0, M = 0;
std::vector< std::string > A;
std::vector< std::string > B;

int main(void){
    std::cin >> N >> M;

    A.resize(N);
    B.resize(M);

    int i, j, k;
    for(i=0;i<N;++i) std::cin >> A[i];
    for(i=0;i<M;++i) std::cin >> B[i];

    int NM = N - M;
    bool f = true;
    for(i=0; i<=NM; ++i){
        for(j=0; j<=NM; ++j){
            f = true;
            for(k=0; k<M; ++k){
                if(A[i+k].substr(j,M) != B[k]){
                    f = false;
                    break;
                }
            }
            if(f){
                goto result;
            }
        }
    }
result:
    if(f){
        std::cout << "Yes\n";
    }else{
        std::cout << "No\n";
    }
}
