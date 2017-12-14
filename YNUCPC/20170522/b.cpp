#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iomanip>

int n = 0, m = 0;

int main(void){
    std::cin >> n >> m;

    long double radn = (n%12)*30 + 1.*m/2;
    long double radm = m*6;

    long double ans1 = std::fabs(radn-radm);

    if(radn >= 180){
        radn = 360 - radn;
    }
    if(radm >= 180){
        radm = 360 - radm;
    }

    long double ans2 = std::fabs(radn+radm);

    std::cout << std::fixed << std::setprecision(5)
              << std::min(ans1,ans2) << std::endl;

}
