#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

bool compare(std::pair<int,int> x, std::pair<int,int> y){
    return (x.first != y.first) ? x.first > y.first : x.second < y.second;
}

int n = 0, m = 0;
int main(void){
    int i = 0;
    int j = 0;
    std::vector< std::pair<int,int> > votes;

    int v = 0;
    while(std::cin >> n >> m){
        if(n==0 && m ==0) break;

        votes.resize(m);
        votes.clear();

        for(i=0; i<m; ++i){
            votes[i].first = 0;
            votes[i].second = i+1;
        }

        for(i=0; i<n; ++i){
            for(j=0; j<m; ++j){
                std::cin >> v;
                if(v == 1){
                    votes[j].first += 1;
                }
            }
        }

        std::sort(votes.begin(), votes.begin() + m, compare);
        for(i=0; i<m; ++i){
            std::cout << (i==0 ? "" : " ") << votes[i].second;
        }
        std::cout << std::endl;
    }
}

