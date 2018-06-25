#include<bits/stdc++.h>

std::string A, B;
int main() {
    std::cin >> A >> B;

    int lenA = A.length(), lenB = B.length();

    if(lenA > lenB) {
        std::cout << "GREATER" << std::endl;
    } else if (lenA < lenB) {
        std::cout << "LESS" << std::endl;
    } else {
        int res = A.compare(B);
        if(res > 0) {
            std::cout << "GREATER" << std::endl;
        } else if(res < 0) {
            std::cout << "LESS" << std::endl;
        } else {
            std::cout << "EQUAL" << std::endl;
        }

    }
}