#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N = 0, M = 0;
int D[1000] = {0};
int C[1000] = {0};

int memo[1001][1001];

long dp(int i, int j){

    if(memo[i][j] != -1){
        return memo[i][j];
    }

    if(j > M){
        return memo[i][j] = INT_MAX;
    }
    if(i == N){
        return memo[i][j] = 0;
    }

    long x = dp(i, j+1);
    long y = dp(i+1, j+1);

    if(x == INT_MAX && y == INT_MAX){
        return memo[i][j] = INT_MAX;
    }else if(x == INT_MAX){
        return memo[i][j] = C[j] * D[i] + y;
    }else if(y == INT_MAX){
        return memo[i][j] = x;
    }else{
        return memo[i][j] = min(x, C[j] * D[i] + y);
    }

}

int main(void){

    fill(memo[0],memo[1000], -1);

    cin >> N >> M;
    for(int i=0; i<N; ++i){
        cin >> D[i];
    }
    for(int j=0; j<M; ++j){
        cin >> C[j];
    }
    cout << dp(0, 0) << endl;
}

