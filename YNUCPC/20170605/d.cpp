#include <iostream>
#include <vector>
#include <algorithm>

int N;
long long int W;
std::vector<long long int> v, w;

std::vector< std::vector<long long int> > memo;
long long int dp(int i, long long int W){
    std::cout << i << "," << W << std::endl;

    if(memo[i][W] != -1) return memo[i][W];
    if(i >= N) return memo[i][W] = 0;

    if(W >= w[i]){
        long long int a = dp(i+1, W);
        long long int b = dp(i+1, W-w[i]) + v[i];
        return memo[i][W] = std::max(a,b);
    }else{
        long long int a = dp(i+1, W);
        return memo[i][W] = a;
    }
}

bool vf;
bool wf;

int main(void){
    std::cin >> N >> W;

    v.resize(N);
    w.resize(N);

    vf = wf = true;
    for(int i=0; i<N; ++i){
        std::cin >> v[i] >> w[i];

        if(v[i] > 1000){
            vf = false;
        }
        if(w[i] > 1000){
            wf = false;
        }
    }

    if(vf == false && wf == false){
        vf = true;
    }

    if(vf){
        memo.resize(N+1, std::vector<long long int> W)
    }

    memo.resize(N+1, std::vector<long long int>(W+1, -1));
    std::cout << dp(0,W) << std::endl;
}
