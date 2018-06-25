#include <bits/stdc++.h>

int A, B, C, D;
int main() {
    std::cin >> A >> B >> C >> D;
    std::cout << std::max(0, std::min(B, D) - std::max(A, C)) << std::endl;
}