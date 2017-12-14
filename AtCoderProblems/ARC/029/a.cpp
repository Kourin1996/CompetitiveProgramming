#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> t;
int main(void){
    std::cin >> N;
    t.resize(N);
    for(int i=0; i<N; ++i){
        std::cin >> t[i];
    }
    std::sort(t.begin(), t.end());

    int time1 = 0;
    int time2 = 0;
    for(int i=0; i<N; ++i){
        if(time1 < time2){
            time1 += t[N-i-1];
        }else{
            time2 += t[N-i-1];
        }
    }
    std::cout << std::max(time1, time2) << std::endl;
}
