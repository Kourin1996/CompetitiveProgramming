#include <iostream>
#include <iomanip>

int A, B, C;
int main(void){
    std::cin >> A >> B >> C;
    std::cout << std::fixed << std::setprecision(10) << (1.*C/A)*B << std::endl;
}