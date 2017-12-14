#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> a;

int main(void){
    int x = 0;
    for(int i=0; i<3; ++i){
        std::cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    std::cout << a[1] << std::endl;
}
