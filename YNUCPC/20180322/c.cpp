#include<bits/stdc++.h>

// Shrotening
#define fst first
#define snd second
#define pb push_back

#define REP(i,a) for(long i=0;i<(a);++i)
#define SORT(a) std::sort((a).begin(), (a).end())
#define EACH(i,a) for(auto (i)=(a).begin(),_END=(a).end();i!=_END;++i)

typedef long long LL;
typedef std::pair<int,int> PII;

int N;
LL K;

std::vector< PII > arr;
int main() {
    std::cin >> N >> K;
    REP(i, N) {
        int a, b;
        std::cin >> a >> b;
        arr.pb(std::make_pair(a, b));
    }
    SORT(arr);

    int i = 0;
    while(K > arr[i].snd) K -= arr[i++].snd;
    std::cout << arr[i].fst << std::endl;
}