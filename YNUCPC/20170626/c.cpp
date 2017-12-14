#include <iostream>
#include <vector>
#include <cstdlib>

int N, Q;
std::vector<int> imos;

int main(void){
    std::cin >> N >> Q;

    imos.resize(N, 0);

    int l, r;
    for(int i=0; i<Q; ++i){
        std::cin >> l >> r;
        if(l != r){
            ++imos[l-1];
            --imos[r-1];
        }
        else{
            ++imos[l-1];
        }
    }

    int sum = 0;
    int old = 0;
    int state = 0;
    for(int i=0; i<N; ++i){
        sum += imos[i];

        if( old != sum ){
            state = (state == 0) ? 1 : 0;
        }
        std::cout << state;

        old = sum;
    }
    std::cout << std::endl;
}
