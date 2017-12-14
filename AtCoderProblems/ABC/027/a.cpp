#include <iostream>
#include <map>
int l = 0;
std::map<int,int> mp;
int main(void){
    for(int i=0; i<3; ++i){
        std::cin >> l;
        mp[l]++;
    }
    for(auto it = mp.begin(),_END = mp.end(); it != _END; ++it){
        if(it->second%2 == 1){
            std::cout << it->first << std::endl;
            return 0;
        }
    }
}
