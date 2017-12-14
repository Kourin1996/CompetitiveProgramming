#include <iostream>

int N;
std::string S;
int P;

int main(void){
    std::cin >> N;

    int sum = 0;
    std::string maxS = "";
    int maxP = 0;
    for(int i=0; i<N; ++i){
        std::cin >> S >> P;
        sum += P;
        if(maxP < P){
            maxS = S;
            maxP = P;
        }
    }

    std::cout << ((sum/2 < maxP) ? maxS : "atcoder") << std::endl;
}
