#include <iostream>
#include <vector>

int N;
std::vector<int> a,b;
std::vector<int> t;

int main(void){
    std::cin >> N;
    a.resize(N);
    b.resize(N);
    t.resize(1000000, 0);
    for(int i=0; i<N; ++i){
        std::cin >> a[i] >> b[i];
        ++t[a[i]];
        --t[b[i]];
    }


}

