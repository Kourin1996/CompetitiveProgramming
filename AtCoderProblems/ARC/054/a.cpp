#include <iostream>
#include <algorithm>
#include <iomanip>
int L, X, Y, S, D;
int main(void){
    std::cin >> L >> X >> Y >> S >> D;

    std::cout << std::fixed << std::setprecision(7);

    if( S == D ){
        std::cout << 0 << std::endl;
        return 0;
    }

    if(D > S){
        if( X < Y ){
            std::cout << std::min( (long double)(D-S)/(X+Y), (long double)(S+L-D)/(Y-X) ) << std::endl;
        }else{
            std::cout << (long double)(D-S)/(X+Y) << std::endl;
        }
    }else{
        if( X < Y ){
            std::cout << std::min( (long double)(S-D)/(Y-X), (long double)(D+L-S)/(Y+X)) << std::endl;
        }else{
            std::cout << (long double)(L-S+D)/(X+Y) << std::endl;
        }
    }
}
