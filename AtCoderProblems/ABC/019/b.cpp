#include <iostream>
#include <vector>
#include <utility>
#include <string>

std::string s;

int main(void){
    std::pair<char, int> p;
    std::vector< std::pair<char,int> > buf(0);
    buf.reserve(1000);

    std::cin >> s;
    for(auto itr = s.begin(); itr != s.end(); ++itr){
        char c = *itr;
        if(buf.empty() || (p = buf.back()).first != c){
            p = std::make_pair(c,1);
            buf.push_back(p);
        }else{
            p.second  = p.second + 1;
            buf.pop_back();
            buf.push_back(p);
        }
    }

    for(auto itr = buf.begin(); itr!=buf.end(); ++itr){
        std::cout << itr->first << itr->second;
    }
    std::cout << std::endl;
}
