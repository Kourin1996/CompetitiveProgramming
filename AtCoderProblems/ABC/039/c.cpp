#include<bits/stdc++.h>

std::string ans[] = {"Mi", "Do", "La", "Fa", "Re", "Si", "So"};
int main() {
    std::string S;
    std::cin >> S;

    int pos = S.find("WW");
    pos += S.find("WW", pos + 1);

    std::cout << ans[pos%7] << std::endl;
}



