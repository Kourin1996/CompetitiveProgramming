#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int func(int x){
    return max(0, 1001 - abs(1000 - x));
}

int main(){
    int n;
    while(cin >> n){
        int ans = 0;
        for(int i = 0; i <= n; ++i){
            ans += func(i) * func(n - i);
        }
            cout << ans << endl;
    }
}
