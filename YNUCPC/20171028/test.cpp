#include <iostream>

int gcd(int a, int b) {
    int min = std::min(a,b);
    int max = std::max(a,b);

    if(min == 0) return max;
    else         return gcd(min, max%min);
}


int a, b;
int main() {
    while(std::cin >> a >> b, a != 0 && b != 0){
        std::cout << a << "," << b << " => " << gcd(a,b) << std::endl;
    }
}