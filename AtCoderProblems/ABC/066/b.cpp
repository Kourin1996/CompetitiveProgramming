#include <iostream>
#include <string>

std::string S;
int dfs(int l){
    if(l == 1)     return 1;
    if(l % 2 == 1) return dfs(l-1);

    bool f = true;
    for(int i=0; i<l/2;++i){
        if(S[i] != S[i+l/2]){
            f = false;
            break;
        }
    }
    return f ? l : dfs(l-1);
}
int main(){
    std::cin >> S;
    int ans = dfs(S.length()-1);
    std::cout << ans << std::endl;
}
