#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

int txa, tya, txb, tyb, T, V;
int n;
std::vector<int> x;
std::vector<int> y;

int main(void){
    int i;
    std::cin >> txa >> tya >> txb >> tyb >> T >> V;
    std::cin >> n;

    x.resize(n);
    y.resize(n);

    bool f = false;
    for(i=0; i<n; ++i){
        std::cin >> x[i] >> y[i];

        double dis_1 = sqrt( (txa-x[i])*(txa-x[i]) + (tya-y[i])*(tya-y[i]) );
        double dis_2 = sqrt( (txb-x[i])*(txb-x[i]) + (tyb-y[i])*(tyb-y[i]) );

        if( (dis_1+dis_2)/V <= T ){
            f = true;
            break;
        }
    }
    if(f){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
}
