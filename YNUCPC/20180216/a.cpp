#include <bits/stdc++.h>
char a, b;
int main() {
    std::cin >> a >> b;

    if( (a == 'H') ^ (b == 'H') ) {
        std::cout << "D" << std::endl;
    } else {
        std::cout << "H" << std::endl;
    }
}