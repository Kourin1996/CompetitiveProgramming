#include <bits/stdc++.h>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;
    std::cout << (B == C ? A : A == C ? B : C) << std::endl;
}