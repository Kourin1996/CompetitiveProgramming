#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> box(3,0);
std::vector<int> bag(3,0);

int main(void){
    std::cin >> box[0] >> box[1] >> box[2];
    std::cin >> bag[0] >> bag[1] >> bag[2];

    std::sort(bag.begin(), bag.end());

    int ans = 0;
    do{
        int res = 1;
        for(int i=0; i<box.size(); ++i){
            res *= box[i]/bag[i];
        }
        ans = std::max(ans, res);

    }while( next_permutation(bag.begin(), bag.end()) );
    std::cout << ans << std::endl;
}
