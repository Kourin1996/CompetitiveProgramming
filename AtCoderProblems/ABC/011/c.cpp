#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int N;
std::vector<int> NG(3);

bool dfs(int n, int i, int j){
    if( n <= 0 )   return true;
    if( j >= 100 ) return false;

    while( i < 3 ){
        if( n > NG[i] ){
            break;
        }else if( n == NG[i] ){
            return false;
        }else{
            ++i;
        }
    }

    for(int k=3; k>=1; --k){
        if( (n/k <= 100-j) && dfs(n-k, i, j+1) ) return true;
    }

    return false;
}

int main(void){
    std::cin >> N;
    for(int i=0; i<3; ++i) std::cin >> NG[i];
    std::sort(NG.begin(), NG.end(), std::greater<int>());

    if(dfs(N,0,0)){
        std::cout << "YES\n";
    }else{
        std::cout << "NO\n";
    }
}
