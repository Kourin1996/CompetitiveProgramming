#include <iostream>
int N = 0;
int main(void){
    std::cin >> N;
    int sum = 0;
    for(int i=1; i<=N; ++i){
        sum += i*10000;
    }
    std::cout << 1.*sum/N << std::endl;
}
