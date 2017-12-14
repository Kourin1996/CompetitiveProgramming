#include <iostream>
#include <map>
#include <string>

std::map<std::string,int> week {
    {"Sunday",   0},
    {"Monday",   5},
    {"Tuesday",  4},
    {"Wednesday",3},
    {"Thursday", 2},
    {"Friday",   1},
    {"Saturday", 0}
};

int main(void){
    std::string day;
    std::cin >> day;
    std::cout << week[day] << std::endl;
}
