#include <iostream>
#include <vector>

int N, K;
std::vector<long long int> a;

int main(void){
    std::cin >> N >> K;
    a.resize(N);
    for(int i=0; i<N; ++i){
        std::cin >> a[i];
    }

    long long int sub = 0;
    for(int i=0; i<K; ++i){
        sub += a[i];
    }

    long long int sum = 0;
    int left = 0, right = K-1;

    while(right < N){
        sum += sub;

        sub -= a[left++];
        sub += a[++right];
    }

    std::cout << sum << std::endl;
}
