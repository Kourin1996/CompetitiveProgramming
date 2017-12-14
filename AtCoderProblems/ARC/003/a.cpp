#include <iostream>
#include <iomanip>
int N = 0;
int main(void){
    char c = 0;

    int sum = 0;
    std::cin >> N;
    for(int i=0; i<N; ++i){
        std::cin >> c;
        sum += (  c == 'A' ? 4
                : c == 'B' ? 3
                : c == 'C' ? 2
                : c == 'D' ? 1
                :            0);
    }
    std::cout << std::fixed << std::setprecision(12) << 1.*sum/N << std::endl;
}
