#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> a(5,0);
std::vector<int> res;

void dfs(int i, int cnt, int sum){
    if(cnt >= 3){
        res.push_back(sum);
        return;
    }
    if(i >= 5){
        return;
    }

    dfs(i+1, cnt,   sum);
    dfs(i+1, cnt+1, sum+a[i]);
}

int main(void){
    for(int i=0; i<5; ++i){
        std::cin >> a[i];
    }

    res.reserve(100);
    dfs(0,0,0);

    std::sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    std::cout << res[res.size() - 3] << std::endl;
}
