#include <iostream>

double s = 0, e = 0;

int main(void){
    double ans = 0.0;
    for(int i=0; i<3; ++i){
        std::cin >> s >> e;
        ans += s * e / 10;
    }
    std::cout << (int)ans << std::endl;
}
