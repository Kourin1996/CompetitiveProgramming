#include <iostream>
#include <iomanip>
double Height = 0.0, BMI = 0.0;
int main(void){
    std::cin >> Height >> BMI;
    double Weight = Height*Height*BMI/10000;
    std::cout << std::fixed
              << std::setprecision(3)
              << Weight
              << std::endl;
}
