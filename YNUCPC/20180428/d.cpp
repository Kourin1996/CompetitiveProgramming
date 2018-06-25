#include <bits/stdc++.h>
 
// Shrotening
#define fst first
#define snd second
#define pb push_back
 
#define REP(i,a) for(long i=0;i<(a);++i)

//alias
typedef std::vector<int>  VI;
typedef std::vector< VI > VI2;

typedef std::pair<int,int> PII;
 
int N;
std::vector< PII > d(1000);
VI2 dp(1003, VI(1003));
 
int main() {
    while(std::cin >> N, N != 0) {
        REP(i, N) {
            std::cin >> d[i].fst >> d[i].snd;
        }
        std::sort(d.begin(), d.begin() + N);
 
        int sum = 0;
        REP(i, N-1) {
            //1~N-1までの和
            sum += d[i].fst;
        }
        if(sum >= d[N-1].fst) {
            int ans = 0;
            REP(i, N) {
                ans += (d[i].fst + d[i].snd);
            }
            std::cout  << ans << std::endl;
        } else {
            dp.assign(1003, VI(1003, 0));
            dp[0][0] = 1;
 
            int rem = d[N-1].fst - sum;
            REP(i, N-1) {
                REP(j, rem + 1) {
                    dp[i+1][j] |= dp[i][j];
                    dp[i+1][j + d[i].snd] |= dp[i][j];
                }
            }
 
            int maxi = 0;
            REP(i, rem + 1) {
                if(dp[N-1][i]) {
                    maxi = std::max(maxi, (int)i);
                }
            }
 
            int t = rem - maxi;
            REP(i, N) {
                t += d[i].snd;
            }
            std::cout << d[N-1].fst + sum + t << std::endl;
        }
    }
}