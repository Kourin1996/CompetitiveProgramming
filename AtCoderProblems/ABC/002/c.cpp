#include <iostream>
#include <cstdlib>
#include <iomanip>
int ax, ay;
int bx, by;
int cx, cy;
using namespace std;
int main(void){
    std::cin >> ax >> ay;
    std::cin >> bx >> by;
    std::cin >> cx >> cy;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << std::abs( (bx-ax)*(cy-ay) - (by-ay)*(cx-ax) )/2.0 << std::endl;
}

