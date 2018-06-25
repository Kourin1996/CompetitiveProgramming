#include<bits/stdc++.h>

// Shrotening
#define fst first
#define snd second
#define pb push_back

// Loop
#define FOR(i,a,b) for(auto i=(a);i<(b);++i)
#define RFOR(i,a,b) for(auto i=(a);i>=(b);--i)

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

int main(){
	LL N;
    std::cin >> N;
    std::vector<bool> bits;

    REP(i, N/5 + (N%5 != 0)) {
        std::cout << "? ";
        REP(j, N) {
			if(i * 5 <= j && j < (i + 1) * 5){
				std::cout << pow(10, j - i * 5) << " ";
			}else{
				std::cout << 0 << " ";
			}
        }
        std::cout << std::endl << std::flush;

        LL x;
        std::cin >> x;
        while(x) {
            LL y = x % 10;
            if(y == 9 || y == 1) {
                bits.push_back(true);
            } else {
                bits.push_back(false);
            }

            x /= 10;
            x -= (y <= 2 ? 1 : 0);
        }
    }
    std::cout << "! ";
    for(auto x: bits) {
        std::cout << (int)x << " ";
    }
    std::cout << std::endl;
	return 0;
}