#include <iostream>
#include <algorithm>
#include <vector>
int N, K;
std::string S;

const long INF = 1000000007;

std::vector< std::vector< std::vector< long > > > memo;
long dp(int i, int d1, int d2){
    if( d1 > K || d2 > K ) return 0;
    if( i >= N ) return 1;

    if(memo[i][d1][d2] != -1){
        return memo[i][d1][d2];
    }

    long long int ret = 0;
    if( S[i] == '0' || S[i] == '?' ){
        ret += dp(i+1, d1+1, std::max(0, d2-1));
        ret %= INF;
    }
    if( S[i] == '1' || S[i] == '?' ){
        ret += dp(i+1, std::max(0,d1-1), d2+1);
        ret %= INF;
    }
    return memo[i][d1][d2] = ret;
}

int main(void){
    std::cin >> N >> K;
    std::cin >> S;

    memo.resize(N+1, std::vector< std::vector< long > >(N+1, std::vector<long>(N+1, -1)));
    std::cout << dp(0,0,0) << std::endl;
}
