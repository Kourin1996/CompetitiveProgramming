#include <iostream>
#include <algorithm>

int A = 0, B = 0;

int main(void){
    std::cin >> A >> B;
    std::cout << (((1.*B/A - B/A) > 0.0) ? B/A+1 : B/A) << std::endl;
}
