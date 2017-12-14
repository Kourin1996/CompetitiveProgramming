#include <iostream>
#include <vector>

int n;
int l;
int main(void){
    std::cin >> n;
    for(int i=0; i<n; ++i){
        std::cin >> l;
        std::vector<int> a(l);
        for(int j=0; j<l; ++j){
            std::cin >> a[j];
        }

        int base = 0;
        long long int ans = 0;
        for(int j=l-1; j>=0; --j){
            if(base <= a[j]){
                base = a[j];
            }else{
                ans += base - a[j];
            }
        }
        std::cout << ans << std::endl;
    }
}
