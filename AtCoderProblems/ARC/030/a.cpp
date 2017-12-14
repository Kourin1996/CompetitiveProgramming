#include <iostream>
#include <string>
#include <algorithm>
std::string Name;
int main(void){
    std::cin >> Name;
    std::string rName = Name;
    std::reverse(rName.begin(), rName.end());

    int hl = Name.length();
    std::cout << ((Name.substr(0, hl) == rName.substr(0, hl)) ? "YES" : "NO") << std::endl;
}
