#include <iostream>
#include <vector>
#include <algorithm>

int N = 0, L = 0;
std::vector< std::string > S;

int main(void){
    std::cin >> N >> L;

    S.resize(N);
    int i=0;
    for(i=0; i<N; ++i) std::cin >> S[i];

    std::sort(S.begin(), S.end());

    for(i=0; i<N; ++i) std::cout << S[i];
    std::cout << "\n";
}
