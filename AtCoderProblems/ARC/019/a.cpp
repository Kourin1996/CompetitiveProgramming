#include <iostream>
#include <string>
#include <map>

std::map<char,int> table { {'O', 0},
                           {'D', 0},
                           {'I', 1},
                           {'Z', 2},
                           {'S', 5},
                           {'B', 8}};

std::string S;

int main(void){
    for(int i=0; i<=9; ++i){
        table[(char)('0'+i)] = i;
    }

    std::cin >> S;

    long long int res = 0;
    for(int i=0; i<S.length(); ++i){
        res += table[S[i]];
        res *= 10;
    }
    res /= 10;

    std::cout << res << std::endl;
}
