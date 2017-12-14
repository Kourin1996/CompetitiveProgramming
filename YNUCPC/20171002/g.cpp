#include <iostream>
#include <vector>
#include <algorithm>

long N, M;
std::vector<long> X;

bool isAble(long T){
    long l=0;
    for(int i=0; i<M; ++i){
        l = std::min(l,X[i]);
        if(X[i]-l>M) {
            return false;
        }
        long a = X[i]+(M-(X[i]-l)*2);
        long b = X[i]+(M-(X[i]-l))/2;
        l = std::max(a+1,b+1);
    }
    return l>=N;
}

int main(void){
    std::cin >> N >> M;
    X.resize(M);
    for(int i=0; i<M; ++i){
        std::cin >> X[i];
        X[i]--;
    }

    long left = -1, right = N*2;
    long mid = (left+right)/2;
    while(right-left>1){
        mid = (left+right)/2;
        if(isAble(mid)){
            right = mid;
        }else{
            left = mid;
        }
    }
    std::cout << right << std::endl;
}

