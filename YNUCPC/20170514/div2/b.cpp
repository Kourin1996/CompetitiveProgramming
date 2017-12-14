#include <iostream>
#include <vector>

int N;
std::vector<int> k(10000,0);

int main(void){
    while(std::cin>>N, N!=0){
        int num_0 = 0;
        int num_1 = 0;
        for(int i=0; i<N; ++i){
            std::cin >> k[i];
            if(k[i] == 0){
                num_0++;
            }
            if(k[i] == 1){
                num_1++;
            }
        }

        if((num_0+num_1) >= N){
            std::cout << "NA" << std::endl;
            continue;
        }

        std::cout << (N-num_0+1) << std::endl;
    }
}
