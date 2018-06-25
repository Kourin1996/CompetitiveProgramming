#include<bits/stdc++.h>
int X;
int main() {
    std::cin >> X;
    long t = 0;
    while(t*(t+1) < 2*X) t++;
    std::cout << t << std::endl; 
}