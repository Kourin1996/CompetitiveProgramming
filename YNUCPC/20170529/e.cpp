#include <iostream>
#include <vector>
#include <cassert>

int N;
std::vector<int> B;

void swap(int i, int j){
    int tmp = B[i];
    B[i] = B[j];
    B[j] = tmp;
}

bool check(){

}

int main(void){
    std::cin >> N;

    assert(N<=100);

    B.resize(N);
    for(int i=0; i<N; ++i){
        std::cin >> B[i];
    }

    std::cout << dfs(0, N-1) << std::endl;
}
