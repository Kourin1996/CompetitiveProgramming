#include <iostream>
#include <vector>
#include <algorithm>

int N;
long T;
std::vector<int> A, B;

std::vector< std::vector< std::vector< int > > > memo;
int dp(int i, int n, int rest){
    if(i >= N){
        return rest >= 0 ? n : -1;
    }
    if(memo[i][n][rest] != -2) return memo[i][n][rest];

    int a = dp(i+1, n,   rest-A[i]);
    int b = dp(i+1, n+1, rest-B[i]);

    if(a == -1 && b == -1){
        return memo[i][n][rest] = -1;
    }else if(a < 0 || b < 0){
        return memo[i][n][rest] = std::max(a,b);
    }else{
        return memo[i][n][rest] = std::min(a,b);
    }
}

int main(void){
    std::cin >> N >> T;
    A.resize(N);
    B.resize(N);
    memo.resize(N, std::vector< std::vector<int> >(N, std::vector<int>(T+1, -2)));
    for(int i=0; i<N; ++i){
        std::cin >> A[i] >> B[i];
    }
    std::cout << dp(0, 0, T) << std::endl;
}
