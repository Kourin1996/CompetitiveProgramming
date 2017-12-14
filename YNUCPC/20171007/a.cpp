#include <iostream>
#include <string>
#include <algorithm>

std::string str = "DiscoPresentsDiscoveryChannelProgrammingContest2016";

int W;
int main(void){
    std::cin >> W;

    while(str.length() != 0){
        int l = str.length();
        std::cout << str.substr(0, std::min(l, W)) << std::endl;
        if(l <= W){
            break;
        }
        str = str.substr(W);
    }
}