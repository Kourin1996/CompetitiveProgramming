#include <iostream>
#include <string>
#include <set>

int N, K;
std::set<char> D;

bool can(){
    std::string str = std::to_string(N);
    for(auto c : str){
        if(D.count(c) >= 1){
            return false;
        }
    }
    return true;
}

int main(void){
    std::cin >> N >> K;
    char d;
    for(int i=0; i<K; ++i){
        std::cin >> d;
        D.insert(d);
    }
    while(!can()) ++N;
    std::cout << N << std::endl;
}
