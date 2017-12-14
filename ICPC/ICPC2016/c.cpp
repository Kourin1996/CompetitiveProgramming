#include <iostream>
#include <vector>

const long max = 7368791 + 1;
int m, n;

long solve(){
    std::vector<bool> used(max, false);

    long t = m;
    for(int i=0; i<n; ++i){
        while(used[t]) ++t;
        for(int j=1; j*t < max; ++j){
            used[j*t] = true;
        }
        ++t;
    }
    while(used[t]) ++t;
    return t;
}

int main(void){
    while(std::cin >> m >> n, m != 0 && n != 0){
        std::cout << solve() << std::endl;
    }
}
