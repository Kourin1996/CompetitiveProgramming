#include <iostream>
int n = 0;
int main(void){
    long long int a = 1, b = 0, c = 0;
    long long int ai = 0;

    std::cin >> n;
    for(int i=4; i<=n+2; ++i){
        ai = (a + b + c) % 10007;
        c = b % 10007;
        b = a % 10007;
        a = ai % 10007;
    }
    std::cout << c % 10007 << std::endl;
}
