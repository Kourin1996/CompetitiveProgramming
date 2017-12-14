#include <iostream>
#include <string>

void replace(std::string& S, const std::string& from, const std::string& to){
    std::string::size_type pos = 0;
    while( (pos = S.find(from, pos)) != std::string::npos ){
        S.replace(pos, from.size(), to);
        pos += to.size();
    }
}

int main(void){
    std::string S;
    std::getline(std::cin, S);

    replace(S, "Left", "<");
    replace(S, "Right", ">");
    replace(S, "AtCoder", "A");

    std::cout << S << std::endl;
}
