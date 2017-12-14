#include <iostream>
inline int gcd(int a, int b){int c; while( a != 0 ) c=a,a=b%a,b=c;return b;}
int A, B, C;
int main(void){
    std::cin >> A >> B >> C;
    std::cout << ( !(C%gcd(A,B)) ? "YES" : "NO" ) << std::endl;

    std::cout << "GCD:" << gcd(A,B) << std::endl;
}
