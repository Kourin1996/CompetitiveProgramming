#include <iostream>
int a = 0, b = 0, n = 0;

int main(void){
    std:: cin >> a >> b >> n;
    while(n % a != 0 || n % b != 0) n++;
    std::cout << n << std::endl;
}
