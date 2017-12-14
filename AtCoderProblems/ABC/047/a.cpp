#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    std::vector<int> v(3, 0);
    std::cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    std::cout << (((v[0]+v[1]) == v[2]) ? "Yes" : "No") << std::endl;
}
