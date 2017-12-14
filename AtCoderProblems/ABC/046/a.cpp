#include <iostream>
#include <set>
int main(void){
    std::set<int> s;
    int x = 0;
    for(int i=0; i<3; ++i){
        std::cin >> x;
        s.insert(x);
    }
    std::cout << s.size() << std::endl;
}
