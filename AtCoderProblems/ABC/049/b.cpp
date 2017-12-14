#include <iostream>
#include <vector>
int H = 0, W = 0;
std::vector< std::vector<char> > C;
int main(void){
    int i, j ;
    std::cin >> H >> W;
    C.resize(H, std::vector<char>(W, '\0'));
    for(i=0;i<H;++i) for(j=0;j<W;++j) std::cin >> C[i][j];

    for(i=0;i<2*H;++i){
        for(j=0;j<W;++j){
            std::cout << C[i/2][j];
        }
        std::cout << "\n";
    }
}
