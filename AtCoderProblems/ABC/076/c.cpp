#include<bits/stdc++.h>

//Algorithm
#define EACH(i,a) for(auto (i)=(a).begin(),_END=(a).end();i!=_END;++i)
#define ALL(a) (a).begin(), a.end()

std::string S, T;
int main() {
    std::cin >> S;
    std::cin >> T;

    std::set<std::string> pattern;

    int slen = S.length(), tlen = T.length();
    for(int i=0; i+tlen<=slen; ++i) {
        bool f = true;
        std::string str = S;
        for(int j=0; j<tlen; ++j) {
            str[i+j] = T[j];
            if(S[i+j] != '?' && S[i+j] != T[j]) {
                f = false;
                break;
            }
        }
        if(f) {
            pattern.insert(str);
        }
    }

    if(pattern.size() > 0) {
        std::string ans = *std::min_element(ALL(pattern));
        EACH(c, ans) {
            std::cout << (*c == '?' ? 'a' : *c);
        }
        std::cout << std::endl;
    } else {
        std::cout << "UNRESTORABLE" << std::endl;
    }
}