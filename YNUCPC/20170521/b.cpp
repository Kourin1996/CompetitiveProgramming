#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

int N = 0, P = 0;

std::vector< std::pair<int,int> > NP;
std::vector<int> prime;

void genPrime(int n){
    prime.reserve(n);
    prime.push_back(2);
    for(int i=3; i<=n; ++i){
        for(auto it = prime.begin(), END = prime.end(); it != END; ++it){
            if(i % *it == 0) break;
            if(it == (END - 1)){
                prime.push_back(i);
                break;
            }
        }
    }

    for(int i=prime.back();;++i){
        for(auto it=prime.begin(), END = prime.end(); it != END; ++it){
            if(i % *it == 0) break;
            if(it == (END - 1)){
                prime.push_back(i);
                return;
            }
        }
    }
}

long long int solve(int n, int p){
    int left=0;

    while(prime[left] < n) left++;

    int pSize = prime.size();
    std::priority_queue<int> pq;

    int cnt = 0;
    for(int i=left; i<pSize; ++i){
        for(int j=left; j<pSize; ++j){
            pq.push((-1)*(prime[i]+prime[j]));
        }
    }
    int prev = pq.top();
    for(int i=1; i<p-1; ++i){
        if(prev == pq.top()){
            i--;
        }else{
            prev = pq.top();
        }
        pq.pop();
    }
    return pq.top() * -1;
}

int main(void){
    int maxN = 0;
    while(std::cin >> N >> P, (N!=-1 && P!=-1)){
        maxN = std::max(maxN, N);
        NP.push_back(std::make_pair(N,P));
    }

    genPrime(maxN + 1000);

     for(auto it = NP.begin(), END = NP.end(); it != END; ++it){
        std::cout << solve(it->first, it->second) << std::endl;
    }
}
