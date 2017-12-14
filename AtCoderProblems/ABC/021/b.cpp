#include <iostream>
#include <vector>

int N = 0;
int a = 0, b = 0;
int K = 0;
int P = 0;

std::vector<int> cnt(100, 0);

int main(void){
    std::cin >> N;
    std::cin >> a >> b;

    cnt[a-1]++;
    cnt[b-1]++;

    std::cin >> K;
    for(int i=0; i<K; ++i){
        std::cin >> P;
        if(cnt[P-1]++ >= 1){
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    std::cout << "YES" << std::endl;
}
