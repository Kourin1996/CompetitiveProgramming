#include <iostream>
std::string W;
int main(void){
    std::cin >> W;
    for(auto c = W.begin(); c != W.end(); c++){
        if(*c == 'a' || *c == 'i' || *c == 'u' || *c == 'e' || *c == 'o'){
            continue;
        }
        std::cout << *c;
    }
    std::cout << std::endl;
}
