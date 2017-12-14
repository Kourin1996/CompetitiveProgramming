#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N = 0;
map<int,int> mp;

int *memo;

int dp(int i, int prev){
    int res = 1;

    if(i < 0) return 0;
    if(memo[i*N+prev] != -1) return memo[i*N+prev];

    if(mp[i] != prev){
        res += dp(mp[i], i);
    }
    for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
        if(i == it->second && it->first != prev){
            res += dp(it->first, i);
        }
    }
    return memo[i*N+prev] = res;
}

int main(void){
    cin >> N;

    int x = 0;
    for(int i=1; i<=N-1; ++i){
        cin >> x;
        mp[i] = x;
    }

    memo = (int *)malloc(sizeof(int)*N*N);
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            memo[i*N+j] = -1;
        }
    }

    mp[0] = -1;
    for(int i=0; i<N; ++i){
        int mx = dp(mp[i], i);
        for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
            if(i == it->second){
                mx = max(mx, dp(it->first,i));
            }
        }
        cout << mx << endl;
    }

    free(memo);
}
