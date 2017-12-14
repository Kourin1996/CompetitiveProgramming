#include <iostream>
#include <cmath>
int N = 0;
int A = 0;

int main(void){
    int sum = 0;
    int num = 0;

    std::cin >> N;
    for(int i=0; i<N; ++i){
        std::cin >> A;
        if(A > 0){
            sum += A;
            num++;
        }
    }
    std::cout << ceil(1.*sum/num) << std::endl;
}
