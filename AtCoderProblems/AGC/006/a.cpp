#include <iostream>
#include <string>
#include <algorithm>
 
int N;
std::string s, t;
int main() {
    std::cin >> N;
    std::cin >> s;
    std::cin >> t;
    
    int cmn = 0;
    for(int i=0; i<N; ++i) {
        bool f = true;
        for(int j=0; i+j<N; ++j) {
        	if(s[i+j] != t[j]){
	    f = false;
	    break;
        	}
        }
        if(f){
            cmn = std::max(cmn, N-i);        	
        }
    }
    std::cout << 2*N - cmn << std::endl;
}