#include <iostream>
#include <set>
#include <algorithm>

int n;
int a[1001];

long solve(){
    std::set<long> diff;
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if( i == j ) continue;
            diff.insert(abs(a[i]-a[j]));
        }
    }
    return *(std::min_element(diff.begin(), diff.end()));
}

int main(void){
    while(std::cin >> n, n != 0){
        for(int i=0; i<n; ++i){
            std::cin >> a[i];
        }
        std::cout << solve() << std::endl;
    }
}
