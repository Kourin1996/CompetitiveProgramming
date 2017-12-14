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

int N;
VI A, B, C;
int main() {
    std::cin >> N;
    A.resize(N), B.resize(N), C.resize(N);
    REP(i, N) std::cin >> A[i];
    REP(i, N) std::cin >> B[i];
    REP(i, N) std::cin >> C[i];

    SORT(A), SORT(B), SORT(C);

    auto _BEGIN_A = A.begin();
    auto _BEGIN_B = B.begin(), _END_B = B.end();
    auto _END_C   = C.end();

    long long sum = 0;

    auto itb = _BEGIN_B;
    while( itb != _END_B ){
        int b = *itb;
        auto next = std::upper_bound(ALL(B), b);
        long nb = (int)(next - itb);

        auto ita = std::lower_bound(ALL(A), b);
        if(ita == _BEGIN_A) {
            itb = next;
            continue;
        }
        long na = (int)(ita-_BEGIN_A);

        auto itc = std::upper_bound(ALL(C), b);
        if(itc == _END_C) {
            itb = next;
            continue;
        }
        long nc = (int)(_END_C - itc);
        
        sum += na * nb * nc;
        itb = next;
    }
    std::cout << sum << std::endl;
}