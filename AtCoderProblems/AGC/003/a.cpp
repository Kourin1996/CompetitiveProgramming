#include <bits/stdc++.h>

int main() {
    bool N = false, W = false, S = false, E = false;

    char c;
    while(std::cin >> c) {
        if(c == 'N')       N = true;
        else if (c == 'W') W = true;
        else if (c == 'S') S = true;
        else if (c == 'E') E = true;
    }

    bool NS = (!N && !S) || (N && S);
    bool WE = (!W && !E) || (W && E);
    std::cout << (NS && WE ? "Yes" : "No") << std::endl;
}