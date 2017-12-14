#include <iostream>
#include <iomanip>

int main(void){
    long a, b;
    while(std::cin >> a >> b, !(a == 0 && b == 0) ){
        std::cout << std::fixed << std::setprecision(10) << (long double)a/b << std::endl;
    }
}
