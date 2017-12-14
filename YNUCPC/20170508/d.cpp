#include <iostream>
#include <cmath>
#include <cstdio>
int N = 0;
int K = 0;

int main(void){
    std::cin >> N >> K;

    long long int left = K - 1;
    long long int mid  = K;
    long long int right = N - K;

    long long int all_pattern = pow(N, 3);

    long long int pattern1 = left*right*6;
    long long int pattern2 = left*3;
    long long int pattern3 = right*3;

    printf("%.15Lf\n",((long double)(pattern1+pattern2+pattern3+1))/all_pattern);
}
