#include <iostream>
#include <sstream>
#include <algorithm>

inline int toInt(std::string s){int v; std::istringstream iss(s);iss>>v;return v;}

std::string A, B;

int main(void){
    std::cin >> A >> B;

    int ans0 = toInt(A) - toInt(B);

    int ans1 = 0;
    std::string A1 = A;
    if(A1[0] < '9'){
        A1[0] = '9';
    }else{
        if(A1[1] < '9'){
            A1[1] = '9';
        }else{
            A1[2] = '9';
        }
    }
    ans1 = toInt(A1) - toInt(B);

    int ans2 = 0;
    std::string B2 = B;
    if(B2[0] > '1'){
        B2[0] = '1';
    }else{
        if(B2[1] > '0'){
            B2[1] = '0';
        }else{
            B2[2] = '0';
        }
    }
    ans2 = toInt(A) - toInt(B2);

    std::cout << std::max(ans0, std::max(ans1, ans2)) << std::endl;
}
