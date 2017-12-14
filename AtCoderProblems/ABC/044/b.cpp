#include <iostream>
#include <map>

std::string w;
std::map<char,int> mp;

int main(void){
    std::cin >> w;

    bool f = true;
    for(char c = 'a'; c <= 'z'; ++c) mp[c] = 0;
    for(auto it=w.begin(), _END=w.end(); it!=_END; ++it) ++mp[*it];
    for(auto it=mp.begin(), _END=mp.end(); it!=_END; ++it){
        if(it->second%2 != 0){
            f = false;
            break;
        }
    }
    std::cout << (f ? "Yes" : "No") << std::endl;
}
