#include <iostream>
int x, y;
int main(void){
    std::cin >> x >> y;
    std::cout << ( (x < y) ? "Better" : "Worse" ) << std::endl;
}
