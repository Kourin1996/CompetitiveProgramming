#include<bits/stdc++.h>

int A, B, C;
int main() {
    std::cin >> A >> B >> C;
    std::cout << (A <= C && C <= B ? "Yes" : "No") << std::endl;
}