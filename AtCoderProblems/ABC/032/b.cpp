#include <iostream>
#include <set>

std::string s;
int k = 0;

int main(void){
    std::cin >> s;
    std::cin >> k;

    std::set< std::string > st;

    int len = s.length() - k;
    for(int i=0; i<=len; ++i){
        st.insert(s.substr(i,k));
    }
    std::cout << st.size() << std::endl;
}
