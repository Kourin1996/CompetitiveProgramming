#include <iostream>
#include <utility>

std::string S;
std::pair<char,char> ary[] = {{'I','i'}, {'C','c'}, {'T','t'}};

int main(void){
    int i = 0;
    std::cin >> S;
    for(auto c = S.begin(); c != S.end(); ++c){
        if(ary[i].first == *c || ary[i].second == *c){
            i++;
        }
    }
    std::cout << ((i >= 3) ? "YES" : "NO") << std::endl;
}
