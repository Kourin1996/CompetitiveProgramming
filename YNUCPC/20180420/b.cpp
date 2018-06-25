#include <bits/stdc++.h>
 
int N;
std::vector<int> a;
int main(void){
    std::cin >> N;
    a.resize(N);
    for(int i=0; i<N; ++i){
        std::cin >> a[i];
        --a[i];
    }
    
    int b = 0;
    int ans = -1;
    for(int i=0; i<N;++i){
        b = a[b];
        if(b == 1){
            ans = i+1;
            break;
        }
    }
    std::cout << ans << std::endl;
}