#include <iostream>
#include <map>

int N = 0;
std::map<std::string, int> mp;

int main(void){
    std::string S;

    std::cin >> N;
    for(int i=0; i<N; ++i){
        std::cin >> S;
        mp[S] = (mp.find(S) == mp.end()) ? 0 : (mp[S] + 1);
    }

    auto mx = mp.begin();
    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        if(mx->second < itr->second){
            mx = itr;
        }
    }
    std::cout << mx->first << std::endl;
}
