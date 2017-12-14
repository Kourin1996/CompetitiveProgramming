#include <iostream>
#include <vector>
#include <cmath>

int N = 0;
char cs[] = {'a','b','c'};

std::vector<std::string> pattern;

int dfs(int d, std::string str){
    if(d >= N){
        pattern.push_back(str);
    }else{
        for(int i=0; i<3; ++i){
            dfs(d+1, str+cs[i]);
        }
    }
    return 0;
}

int main(void){
    std::cin >> N;
    pattern.reserve(pow(3,N));
    dfs(0, "");
    for(auto itr = pattern.begin(); itr != pattern.end(); ++itr){
        std::cout << *itr << std::endl;
    }
}
