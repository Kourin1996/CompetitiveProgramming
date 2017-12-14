#include <iostream>
char a = 0, b = 0;
int main(void){
    std::cin >> a >> b;
    std::cout << ((a==b) ? 'H' : 'D') << std::endl;
}
