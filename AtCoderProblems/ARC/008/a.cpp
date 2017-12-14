#include <iostream>
#include <algorithm>
int N = 0;
int main(void){
    std::cin >> N;
    std::cout << ((N/10)*100 + (N%10 > 6 ? 100 : (N%10)*15)) << std::endl;
}
