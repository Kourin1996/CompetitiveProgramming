#include <iostream>
#include <algorithm>

int N = 0, A = 0, B = 0;

int main(void){
    std::cin >> N >> A >> B;
    int nb = std::min(5, N);
    int na = std::max(0, N-nb);

    std::cout << na*A + nb*B << std::endl;
}
