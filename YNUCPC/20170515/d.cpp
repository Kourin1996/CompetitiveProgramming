#include <iostream>
#include <cmath>
#include <vector>

long long int N = 0;
long long int memo[10];

int getDigit(int val){
    return (val <= 0) ? 0 : log10(val)+1;
}

long long int dp1(long long int val){
    int digit = getDigit(val) - 1;

    if(val == 0) return memo[0] = 1;
    if(val == 1) return memo[0] = 1;
    if(digit == 1) return memo[1] = 1;
    if(memo[digit] != -1) return memo[digit];

    memo[digit] = 19*dp1(val/10);
    std::cout << val << ":" << memo[digit] << std::endl;
    return memo[digit];
}

long long int dfs(long long int val){
    int digit = getDigit(val);

    if(digit == 0) return 0;

    int ans = 0;

    int m = (int)(val/pow(10,digit-1));
    std::cout << "m:" <<m << std::endl;
    for(int i = pow(10, digit-1); i <= m*pow(10,digit-1); ++i){
        std::cout << i << ",";
    }
    std::cout << std::endl;

    ans += dfs(val - m*pow(10, digit-1)) + 1;

    std::cout << val << ":" << ans << std::endl;

    return ans;
}

int main(void){

    for(int i=0; i<10; ++i) memo[i] = -1;
    memo[0] = 1;

    std::cin >> N;
    dp1(pow(10, getDigit(N) - 1));

    for(int i=0; i<10; ++i){
        std::cout << i << ":" << memo[i] << std::endl;
    }

    dfs(N);
}
