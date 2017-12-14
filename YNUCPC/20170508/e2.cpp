#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N = 0;
map<int,int> p;

int memo [100000] {0}; //sum of subtree
int memo2[100000] {0}; //num of branch

int dfs(int i, int prev){
    int res = 0;
    int cnt = 0;
    if(p[i] != -1 && p[i] != prev){
        res += dfs(p[i], i) + 1;
    }
    for(auto it = p.begin(); it != p.end(); ++it){
        if( it->second == i && it->first != prev){
            res += dfs(it->first, i) + 1;
            cnt++;
        }
    }
    memo [i] = res;
    memo2[i] = max(1,cnt);

    return res;
}

int solve(int i){
    return max(memo[i] - memo2[i] + 1, N - memo[i] - 1);
}

int main(void){
    int x = 0;

    p[0] = -1;
    cin >> N;
    for(int i=1; i<N; ++i){
        cin >> x;
        p[i] = x;
    }
    dfs(0, -1);

    for(int i=0; i<N; ++i){
        cout << solve(i) << endl;
    }
}
