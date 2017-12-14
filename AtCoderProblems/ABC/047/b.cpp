#include <iostream>
#include <algorithm>
int W =0, H = 0, N = 0;
int main(void){
    std::cin >> W >> H >> N;
    int x,y,z;
    int a = 0, b = 0, c = W, d = H;
    for(int i=0; i<N; ++i){
        std::cin >> x >> y >> z;
        if(z == 1)      a = std::max(a, x);
        else if(z == 2) c = std::min(c, x);
        else if(z == 3) b = std::max(b, y);
        else if(z == 4) d = std::min(d, y);
    }
    if(c<a || d<b) std::cout << 0 << std::endl;
    else           std::cout << (c-a)*(d-b) << std::endl;
}
