#include <bits/stdc++.h>

long A, B, C;
int main() {
    std::cin >> A >> B >> C;

    long V  = A * B * C;
    long V1 = (A/2) * B * C;
    long V2 = A * (B/2) * C;
    long V3 = A * B * (C/2);

    std::cout << std::min(
        std::min(
            std::abs((V-V1) - V1),
            std::abs((V-V2) - V2)
        ),
        std::abs((V-V3) - V3)
    ) << std::endl;
}
