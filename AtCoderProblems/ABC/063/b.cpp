#include <iostream>
#include <vector>

#define EACH(i,a) for(auto(i)=(a).begin(),_END=(a).end();i!=_END;++i)

std::string S;

std::vector<int> cnt;

int main(void){
    std::cin >> S;

    cnt.resize((int)('z'-'a'+1), 0);
    bool f = true;
    EACH(it,S){
        if(++cnt[*it-'a'] >= 2){
            f = false;
            break;
        }
    }
    std::cout << (f ? "yes" : "no") << std::endl;
}
