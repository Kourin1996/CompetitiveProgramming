#include <iostream>
#include <cmath>
#include <iomanip>
int a, l, x;

long double square(long double a, long double b, long double c){
    long double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main(void){
    while(std::cin >> a >> l >> x){
        long double S1 = square(a,l,l);
        long double S2 = 2*square(l, (1.*l+x)/2, (1.*l+x)/2);
        std::cout << std::fixed << std::setprecision(10) << S1+S2 << std::endl;
    }
}
