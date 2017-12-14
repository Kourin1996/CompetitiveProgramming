#include <iostream>
#include <algorithm>

std::string S;
int N = 0;

int main(void){
    std::cin >> S;
    std::cin >> N;

    sort(S.begin(), S.end());

    std::cout << S[(N-1)/5] << S[(N-1)%5] << std::endl;
}
