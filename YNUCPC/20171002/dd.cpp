#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int N;
long T;
std::vector< std::pair<int, int> > A, B, C;
int main(void){
    std::cin >> N >> T;
    A.resize(N);
    B.resize(N);
    C.resize(N);

    int a, b;
    long sumA = 0, sumB = 0;
    for(int i=0; i<N; ++i){
        std::cin >> a >> b;
        A[i].first = a;
        A[i].second = i;

        B[i].first = b;
        B[i].second = i;

        C[i].first = a - b;
        C[i].second = i;

        sumA += a;
        sumB += b;
    }

    std::sort(C.begin(), C.end());

    long surplus = sumA - T;
    if(surplus <= 0){
        std::cout << 0 << std::endl;
    }else if(surplus - (sumA-sumB) > 0){
        std::cout << -1 << std::endl;
    }else{
        int cnt = 0;
        for(int i=N-1; i>=0; i--){
            surplus -= C[i].first;
            cnt++;
            if(surplus <= 0) break;
        }
        std::cout << cnt << std::endl;
    }
}
