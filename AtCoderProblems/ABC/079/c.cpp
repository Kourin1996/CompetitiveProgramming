#include<bits/stdc++.h>

// Shrotening
#define fst first
#define snd second
#define pb push_back

// Loop
#define FOR(i,a,b) for(long i=(a);i<(b);++i)
#define RFOR(i,a,b) for(long i=(a);i>=(b);--i)

#define REP(i,a) for(long i=0;i<(a);++i)
#define RREP(i,a) for(long i=(a);i>=0;--i)

#define EACH(i,a) for(auto (i)=(a).begin(),_END=(a).end();i!=_END;++i)
#define REACH(i,a) for(auto (i)=(a).rbegin(),_END=(a).rend();i!=_END;++i)

//Algorithm
#define ALL(a) (a).begin(), a.end()
#define RALL(a) (a).rbegin(), a.rend()
#define EXIST(a,x) ((a).find(x)!=(a).end())
#define SORT(a) std::sort((a).begin(), (a).end())
#define UNIQUE(a) std::sort((a).begin(), a.end()), a.erase(std::unique((a).begin(), a.end()), a.end());
#define SUM(a) std::accumulate((a).begin(), (a).end(), 0);

//Setting
#define OPT std::cin.tie(0);std::ios::sync_with_stdio(false);

//debug message
bool debug = true;
#define MSG(s)   if(debug){std::cout << s << std::endl;}
#define DEBUG(x) if(debug){std::cout << "debug(" << #x << "): " << x << std::endl;}

//alias
typedef long long LL;
typedef std::vector<char> VC;
typedef std::vector<int>  VI;
typedef std::vector<long> VL;
typedef std::vector<long long> VLL;

typedef std::vector< VC > VC2;
typedef std::vector< VI > VI2;
typedef std::vector< VL > VL2;
typedef std::vector< VLL > VLL2;

typedef std::pair<int,int> PII;

int len;
std::vector<int> v;
int main() {
    std::string s;
    std::cin >> s;
    len = s.length();
    v.resize(len);
    REP(i, len) {
        v[i] = s[i] - '0';
    }

    int p = (1 << (len-1));
    for(int i=0; i<p; ++i) {
        int ans = v[0];
        for(int k=0; k<len-1; ++k) {
            if( (i>>(len-k-2)) & 0x01 ) {
                ans -= v[k+1];
            } else {
                ans += v[k+1];
            }
        }

        if(ans == 7) {
            std::cout << v[0];
            for(int k=0; k<len-1; ++k) {
                if( (i>>(len-k-2)) & 0x01 ) {
                    std::cout << "-";
                } else {
                    std::cout << "+";
                }
                std::cout << v[k+1];
            }
            std::cout << "=7" << std::endl;
            return 0;
        }
    }
}