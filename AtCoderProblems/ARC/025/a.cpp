#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> D(7,0), J(7,0);
int main(void){
    int i;
    for(i=0; i<7; ++i){
        std::cin >> D[i];
    }
    for(i=0; i<7; ++i){
        std::cin >> J[i];
    }
    int ans = 0;
    for(i=0; i<7; ++i){
        ans += std::max(D[i], J[i]);
    }
    std::cout << ans << std::endl;
}
