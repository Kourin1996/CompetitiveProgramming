#include <iostream>
#include <cmath>
#include <iomanip>

int main(void){
    double a = std::sqrt(2) * std::sqrt(3);

    std::cout << std::fixed << std::setprecision(30) << a*a << std::endl;
    std::cout << std::fixed << std::setprecision(30) << std::pow(a,2.0) << std::endl;
}
