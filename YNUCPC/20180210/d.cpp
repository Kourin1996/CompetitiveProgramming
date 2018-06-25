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

int WA, HA, WB, HB;

std::vector< VC > A, B;

std::string pat = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890?";
std::vector< std::map<char,int> > bmTable;

int main() {
    std::cin >> WA >> HA >> WB >> HB;
    A.resize(HA, VC(WA));
    REP(i, HA) REP(j, WA) std::cin >> A[i][j];
    
    B.resize(HB, VC(WB));
    REP(i, HB) REP(j, WB) std::cin >> B[i][j];

    bmTable.resize(HB);
    REP(i, HB) {
        std::map<char, int> map;

        map.insert({'?', 0});
        REP(j, WB) {
            char c = B[i][WB-1-j];
            if(map.count(c) == 0) {
                map.insert({c, j});
            }
        }
        for(char c: pat) {
            if(map.count(c) == 0) {
                map.insert({c, WB});
            }
        }

        bmTable[i] = map;
    }

    long cnt = 0;
    REP(i, HA - HB + 1) {
        int left = 0;
        while(left < WA - WB + 1) {
            int max = 0;
            REP(x, WB) {
                if(max != 0) break;
                REP(y, HB) {
                    char ac = A[i+y][left+WB-1-x];
                    char bc = B[y][WB-1-x];

                    if(ac == '?' || bc == '?' || ac == bc) {
                        continue;
                    } else {
                        int jump = bmTable[y][ac] - x;
                        max = std::max(max, jump);
                    }
                }
            }
            if(max == 0) {
                cnt++;
                left += 1;
            } else {
                left += max;
            }
        }
    }

    std::cout << cnt << std::endl;
}