#include <iostream>
#include <vector>
#include <algorithm>

int N = 0, Q = 0;
std::vector<int> prog;

int main(void){
    int l, r, t;
    int i, j;

    std::cin >> N >> Q;
    prog.resize(N, 0);

    auto _BEGIN = prog.begin();
    for(i=0; i<Q; ++i){
        std::cin >> l >> r >> t;
        std::fill(_BEGIN+l-1, _BEGIN+r, t);
    }

    for(i=0; i<N; ++i){
        std::cout << prog[i] << "\n";
    }
}
