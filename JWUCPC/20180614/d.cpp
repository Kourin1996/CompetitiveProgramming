#include<bits/stdc++.h>

// Shrotening
#define fst first
#define snd second
#define pb push_back
#define mp std::make_pair

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
typedef std::pair<int,int> PII;

typedef std::vector<char> VC;
typedef std::vector<int>  VI;
typedef std::vector<long> VL;
typedef std::vector<long long> VLL;
typedef std::vector<PII> VPII;

typedef std::vector< VC > VC2;
typedef std::vector< VI > VI2;
typedef std::vector< VL > VL2;
typedef std::vector< VLL > VLL2;

int N;
std::vector<std::string> V(12);
VI coeff(10);
int alphabetSize;
std::vector<bool> mostLeft(10);

int sum;
std::vector<bool> used(10);
int dfs(int i) {
    if(i == alphabetSize) return sum == 0;

    int ret = 0;
    REP(d, 10) {
        if(used[d]) continue;
        if(d == 0 && mostLeft[i]) continue;

        used[d] = true;
        sum += d * coeff[i];
        ret += dfs(i+1);
        sum -= d * coeff[i];
        used[d] = false;
    }
    return ret;
}

int main() {
    std::string s, alphabet;;
    while(std::cin >> N && N != 0) {
        alphabet = "";
        REP(i, N) {
            std::cin >> V[i];
            alphabet += V[i];
        }

        UNIQUE(alphabet);
                
        alphabetSize = alphabet.size();
        REP(i, alphabetSize) {
            coeff[i] = 0;
        }
        REP(i, 10) {
            used[i] = false;
            mostLeft[i] = false;
        }

        //left
        REP(i, N-1) {
            int len = V[i].length();
            if(len > 1) mostLeft[(int)alphabet.find(V[i][0])] = true;
            REP(j, len) {
                int p = alphabet.find(V[i][j]);
                coeff[p] += std::pow(10, len-j-1);
            }
        }
        //right
        int len = V[N-1].length();
        if(len > 1) mostLeft[(int)alphabet.find(V[N-1][0])] = true;
        REP(j, len) {
            int p = alphabet.find(V[N-1][j]);
            coeff[p] -= std::pow(10, len-j-1);
        }

        sum = 0;
        std::cout << dfs(0) << std::endl;
    }
}