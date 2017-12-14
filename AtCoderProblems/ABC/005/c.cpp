#include <iostream>
#include <vector>

int T;
int N;
std::vector<int> A;
int M;
std::vector<int> B;

int main(void){
    int i,j;

    std::cin >> T;

    std::cin >> N;
    A.resize(N);
    for(i=0; i<N; ++i){
        std::cin >> A[i];
    }

    std::cin >> M;
    B.resize(M);
    for(i=0; i<M; ++i){
        std::cin >> B[i];
    }

    i = j = 0;
    while( (i<N) && (j<M) ){
        if( (B[j]<=A[i]+T) && (A[i] <= B[j]) ){
            ++i;
            ++j;
        }else{
            ++i;
        }
    }

    if(j >= M){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }
    return 0;
}
