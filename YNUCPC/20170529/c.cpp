#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int N;
std::vector<int> a;

int main(void){
    int i,j,k;

    std::cin >> N;

    a.resize(N);
    for(i=0; i<N; ++i){
        std::cin >> a[i];
    }

    int taka_max = INT_MIN;
    for(i=0; i<N; ++i){
        int aoki_elem = 0;
        int aoki_max  = INT_MIN;
        for(j=0; j<N; ++j){
            if(i == j) continue;

            int aoki = 0;
            for(k=std::min(i,j)+1; k<=std::max(i,j); k+=2){
                aoki += a[k];
            }
            if(aoki_max < aoki){
                aoki_max  = aoki;
                aoki_elem = j;
            }
        }

        int taka = 0;
        for(k=std::min(i, aoki_elem); k<=std::max(i, aoki_elem); k+=2){
            taka += a[k];
        }
        taka_max = std::max(taka_max, taka);
    }
    std::cout << taka_max << std::endl;
}
