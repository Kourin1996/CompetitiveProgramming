#include <iostream>

long long int A = 0, B = 0, C = 0;
const long long int INF = 1000000007;

int main(void){
    std::cin >> A >> B >> C;
    long long int vol = (((A*B)%INF)*C)%INF;
    std::cout << vol << std::endl;
}
