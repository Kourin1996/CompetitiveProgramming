#include<bits/stdc++.h>

// Shrotening
#define fst first
#define snd second
#define pb push_back

// Loop
#define FOR(i,a,b) for(long i=(a);i<(b);++i)
#define RFOR(i,a,b) for(long i=(a);i>=(b);--i)

#define REP(i,a) FOR(i,0,a)
#define RREP(i,a) RFOR(i,a,0)

#define EACH(i,a) for(auto (i)=(a).begin(),_END=(a).end();i!=_END;++i)
#define REACH(i,a) for(auto (i)=(a).rbegin(),_END=(a).rend();i!=_END;++i)

//Algorithm
#define ALL(a) (a).begin(), a.end()
#define RALL(a) (a).rbegin(), a.rend()
#define EXIST(a,x) ((a).find(x)!=(a).end())
#define SORT(a) sort(ALL(a))

//Setting
#define OPT std::cin.tie(0);std::ios::sync_with_stdio(false);

//debug message
bool debug = true;
#define MSG(s)   if(debug){std::cout << s << std::endl;}
#define DEBUG(x) if(debug){std::cout << "debug(" << #x << "): " << x << std::endl;}

//alias
typedef long long LL;
typedef std::vector<int> VI;
typedef std::vector<long> VL;
typedef std::vector<long long> VLL;
typedef std::pair<int,int> PII;

int T;
int n;
std::string A, B;

int solve(int n) {
    int res = 0;
    REP(i, n) {
        int a = A[i] - '0';
        int b = B[i] - '0';
        res += std::min(
            std::abs(a-b),
            std::abs(9-std::max(a,b)+1 + std::min(a,b)) 
        );
    }
    return res;
}
int main() {
    std::cin >> T;
    REP(i, T) {
        std::cin >> n >> A >> B;
        std::cout << "Case " << i+1 << ": " << solve(n) << std::endl;
    } 
}