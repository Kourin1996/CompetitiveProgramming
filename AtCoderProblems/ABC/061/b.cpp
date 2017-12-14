#include <iostream>
#include <vector>

int N, M;
std::vector<int> city;

int main(void){
    int a, b;

    std::cin >> N >> M;
    city.resize(N,0);

    for(int i=0; i<M; ++i){
        std::cin >> a >> b;
        ++city[a-1];
        ++city[b-1];
    }
    for(int i=0; i<N; ++i){
        std::cout << city[i] << std::endl;
    }
}

