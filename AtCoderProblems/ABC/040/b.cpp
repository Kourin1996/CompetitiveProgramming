#include <iostream>
#include <cmath>
#include <algorithm>
int n = 0;
int main(void){
    std::cin >> n;

    int a = sqrt(n);
    int b = 0;
    int min = n-1;
    while(a >= 1){
        b = n/a;

        if(b-a >= min) break;

        int val = (b-a) + (n-b*a);
        min = std::min(min, val);

        a--;
    }
    std::cout << min << std::endl;
}
