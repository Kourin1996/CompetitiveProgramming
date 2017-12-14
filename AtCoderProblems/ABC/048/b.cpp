#include <iostream>
#include <algorithm>
long long int a = 0, b = 0, x = 0;
int main(void){
    std::cin >> a >> b >> x;
    while(a%x != 0) a++;
    while(b%x != 0) b--;
    std::cout << b/x-a/x+(a%x==0) << std::endl;
}
