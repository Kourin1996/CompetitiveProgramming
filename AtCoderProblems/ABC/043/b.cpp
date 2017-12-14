#include <iostream>

std::string s;

int main(void){
    std::cin >> s;

    std::string text = std::string(10, '\0');
    int i = 0;
    for(auto it=s.begin(), _END = s.end(); it != _END; ++it){
        if(*it == 'B'){
            if(--i<0) i=0;
        }else{
            text[i++] = *it;
        }
    }
    std::cout << text.substr(0,i) << std::endl;
}
