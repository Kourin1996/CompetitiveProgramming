#include <iostream>
#include <string>
std::string X;
int main(void){
    std::cin >> X;
    for(auto itr = X.begin(); itr != X.end(); ++itr){
        if(*itr == 'o' || *itr == 'k' || *itr == 'u'){
            continue;
        }else if(*itr == 'c' && *(itr+1) == 'h'){
            itr++;
            continue;
        }else{
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    std::cout << "YES" << std::endl;
    return 0;
}
