#include<bits/stdc++.h>
std::string a, b, c;
int main() {
    std::cin >> a >> b >> c;
    std::cout << (char)std::toupper(a[0])
              << (char)std::toupper(b[0])
              << (char)std::toupper(c[0])
              << std::endl;
}