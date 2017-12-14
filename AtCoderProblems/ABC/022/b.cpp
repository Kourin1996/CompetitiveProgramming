#include <iostream>
#include <vector>

int N = 0;
std::vector<int> A(100000,0);

int main(void){
    std::cin >> N;

    int a   = 0;
    int sum = 0;
    for(int i=0; i<N; ++i){
        std::cin >> a;
        if(++A[a-1] >= 2){
            sum += 1;
        }
    }

    std::cout << sum << std::endl;
}
