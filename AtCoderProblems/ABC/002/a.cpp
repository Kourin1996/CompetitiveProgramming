#include <iostream>
long int X = 0, Y = 0;
int main(void){
    std::cin >> X >> Y;
    std::cout << ((X>Y) ? X : Y) << std::endl;
}
