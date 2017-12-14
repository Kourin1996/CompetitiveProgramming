#include<bits/stdc++.h>

#define REP(i,a) for(long i=0;i<(a);++i)

typedef long long LL;
typedef std::vector<int>  VI;
typedef std::vector< VI > VI2;
typedef std::pair<int,int> PII;

VI raw(100002, 0), col(100002, 0), cn(100002,0);
int R, C, K, N;
int main(){
    std::cin >> R >> C >> K;
    std::cin >> N;
    std::vector< PII > v;

    REP(i, N) {
        int r, c;
        std::cin >> r >> c;
        raw[r]++;
        col[c]++;
        v.push_back(std::make_pair(r,c));
    }

    REP(i, C) cn[col[i+1]]++;

    LL ans = 0;
    REP(i, R) {
        int j = K - raw[i+1];
        if(j >= 0) ans += cn[j];
    }

    for(auto p : v){
        if(raw[p.first] + col[p.second] == K + 1)  ans++;
        else if(raw[p.first] + col[p.second] == K) ans--;
    }
   std::cout << ans << std::endl;
}