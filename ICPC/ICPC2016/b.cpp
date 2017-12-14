#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const int nAlpha = (int)('Z'-'A')+1;

int n;
char c[100];

void solve(){
    std::vector< std::pair<int,char> > vote(nAlpha);
    for(int i=0; i<nAlpha; ++i){
        vote[i].first = 0;
        vote[i].second = i + 'A';
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<nAlpha; ++j){
            if(vote[j].second == c[i]){
                ++vote[j].first;
                break;
            }
        }

        std::sort(vote.begin(), vote.end());

        int first  = vote[nAlpha-1].first;
        int second = vote[nAlpha-2].first;
        int remain = n-i-1;

        if(first > second + remain){
            std::cout << vote[nAlpha-1].second << " " << i+1 << std::endl;
            return;
        }
    }
    std::cout << "TIE" << std::endl;
    return;
}

int main(void){
    while(std::cin >> n, n != 0){
        for(int i=0; i<n; ++i){
            std::cin >> c[i];
        }
        solve();
    }
}
