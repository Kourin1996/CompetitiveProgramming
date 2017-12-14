#include <iostream>
#include <vector>
#include <utility>
#include <string>

int n = 0, m = 0, k = 0;
std::vector<char> c;
std::vector<int>  cnt;
std::vector<int>  got;
std::vector< std::pair<int,int> > ab;
std::vector< std::string > ls;

void dfs(int i, std::string sub){
    if(sub.length() >= k){
        ls.push_back(sub);
        return;
    }

    if(cnt[i] >= n){
        return;
    }
    cnt[i]++;

    for(int j=1; j<=m; ++j){
        if(ab[j].first == i){
            if(got[i] == 0){
                got[i] = 1;
                dfs(ab[j].second, sub+c[i]);
                got[i] = 0;
            }
            dfs(ab[j].second, sub);
        }
    }

    if(sub.length() == k-1 && got[i] == 0){
        ls.push_back(sub+c[i]);
    }

    cnt[i]--;
    return;
}

int main(void){
    int i,j;

    std::cin >> n >> m >> k;
    c.resize(n+1);
    cnt.resize(n+1);
    got.resize(n+1);
    for(i=1; i<=n; ++i) std::cin >> c[i];

    ab.resize(m+1);
    for(i=1; i<=m; ++i){
        std::cin >> ab[i].first >> ab[i].second;
    }

    for(i=1; i<=n; ++i){
        dfs(i, "");
    }

    if(ls.size() == 0){
        std::cout << "-1" << std::endl;
    }else{
        auto mn = ls.begin();
        for(auto it = ls.begin()+1; it != ls.end(); ++it){
            if(*mn > *it){
                mn = it;
            }
        }
        std::cout << *mn << std::endl;
    }
}
