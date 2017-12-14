#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>

int e = 0;

int solve(){
    int x,y,z;
    int z_max;
    int res = INT_MAX;
    for(y=0; y<=e; ++y){
        if((e-y*y) < 0){
            break;
        }
        z_max = pow(e-y*y, 1.0/3.0) + 1;
        for(z=0;z<=z_max;++z){
            x = e - y*y - z*z*z;
            if(x >= 0){
               res = std::min(res, x+y+z);
            }else{
                break;
            }
        }
    }
    return res;
}

int main(void){
    while(true){
        std::cin >> e;
        if(e == 0) break;
        std::cout << solve() << std::endl;
    }
}
