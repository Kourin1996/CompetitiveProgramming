#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

int K, N;
std::vector< std::pair<int, std::string> > vw;

std::map<std::string, int> mp;

int main(void){
    std::cin >> K >> N;
    vw.resize(N);
    for(int i=0; i<N; ++i){
        std::cin >> vw[i].first >> vw[i].second;
    }

    std::sort(vw.begin(), vw.end());

    for(int i=0; i<N; ++i){
        std::string val = std::to_string(vw[i].first);
        std::string str = vw[i].second;

        for(int i=0; i<val.size(); ++i){

        }
    }
}
