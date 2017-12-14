#include <iostream>
#include <vector>
#include <cstdlib>

const int coin[] = {1,5,10,50,100,500};

int n;
std::vector<int> p(100);

unsigned long int getBits(unsigned long int coins, int i){
    return ( (coins>>i*4)&0x000F );
}
unsigned long int setBits(unsigned long int coins, int i, int v){
    return (coins |= ( (0x000F&v) << i*4));
}

int dp(int i, unsigned long int coins){
    if(i >= n){
        return 0;
    }


}


int main(void){
    int i;
    unsigned long int coins;//4bit区切り
    while(std::cin >> n){
        if(n == 0) break;
        for(int i=0; i<n; ++i){
            std::cin >> p[i];
        }
        coins = 0x0000;
    }
}

