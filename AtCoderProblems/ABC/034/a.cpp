#include <iostream>

int x = 0, y = 0;

int main(void){
    std::cin >> x >> y;
    std::cout << ((x < y) ? "Better" : "Worse") << std::endl;
}
