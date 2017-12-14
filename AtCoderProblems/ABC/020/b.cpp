#include <iostream>
#include <cmath>

int A = 0;
int B = 0;

int main(void){
    std::cin >> A >> B;

    int ans = (A*pow(10, (int)log10(B)+1) + B)*2;

    std::cout << ans << std::endl;
}
