#include <iostream>
int Y = 0;
int main(void){
    std::cin >> Y;
    std::cout << ( Y%400 == 0 ? "YES"
                  :Y%100 == 0 ? "NO"
                  :Y%4   == 0 ? "YES"
                  :             "NO") << std::endl;
}
