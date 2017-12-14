#include <iostream>
#include <climits>
int N = 0;
int main(void){
    int res = INT_MAX;
    int x   = 0;

    std::cin >> N;
    for(int i=0; i<N; ++i){
        std::cin >> x;
        res = x < res ? x : res;
    }
    std::cout << res << std::endl;
}
