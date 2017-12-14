#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int N = 0, M = 0;
std::vector< std::pair<int,int> > thread;

int main(void){
    int i;
    std::cin >> N >> M;

    thread.resize(N);
    for(i=0; i<N; ++i){
        thread[i].first = 0;
        thread[i].second = i+1;
    }

    int x = 0;
    int top = 0;
    for(i=0; i<M; ++i){
        std::cin >> x;
        thread[x-1].first = --top;
    }

    std::sort(thread.begin(), thread.end());

    for(i=0; i<N; ++i){
        std::cout << thread[i].second << "\n";
    }
}
