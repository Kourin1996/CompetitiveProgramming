#include <bits/stdc++.h>
int W, a, b;
int main() {
    std::cin >> W >> a >> b;
    std::cout << std::max(0, std::abs(a-b) - W) << std::endl;
}