#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int N, K;
std::vector<long> a, b;
std::vector<long long int> c;

int main(void){
    std::cin >> N >> K;

    a.resize(N);
    b.resize(N);
    for(int i=0; i<N; ++i) std::cin >> a[i];
    for(int i=0; i<N; ++i) std::cin >> b[i];

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    long long int low, high = (1ll << 61);
    long long int mid = (low+high)/2;

    while( low+1 < high ){
        int k = 0;
        for(int i=0; i<N; ++i){
            if(mid < b[i]) break;
            int pos = upper_bound(a.begin(), a.end(), mid/b[i]) - a.begin();
            k += pos;
        }

        if(k >= K) high = mid;
        else       low  = mid;

        mid = (low + high)/2;
    }

    std::cout << high << std::endl;
}
