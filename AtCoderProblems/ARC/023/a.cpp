#include <iostream>
int y = 0, m = 0, d = 0;
int main(void){
    std::cin >> y >> m >> d;
    if(m <= 2){
        y -= 1;
        m += 12;
    }

    int ans = 735798 - 365*y - y/4 + y/100 - y/400 - 306*(m+1)/10 - d;

    std::cout << ans << std::endl;
}
