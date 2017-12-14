#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int N = 0;
int L = 0;
tuple<int, int, int> lamp[100000];

int dfs(int i, int x){

    cout << i << "," << x << endl;

    if(x >= L) return 0;
    if(i >= N) return -1;

    int next_left = get<0>(lamp[i+1]);

    if(x < next_left){
        return get<2>(lamp[i]) + dfs(i+1, get<1>(lamp[i]));
    }else{
        int ret1 = dfs(i+1, x);
        int ret2 = get<2>(lamp[i]) + dfs(i+1, get<1>(lamp[i]));

        if(ret1 != -1 && ret2 != -1){
            return min(ret1, ret2);
        }else if(ret1 == -1){
            return ret2;
        }else if(ret2 == -1){
            return ret1;
        }else{
            return -1;
        }
    }
}

int main(void){
    cin >> N >> L;

    int l = 0, r = 0, c = 0;

    for(int i=0; i<N; ++i){
        cin >> l >> r >> c;
        lamp[i] = make_tuple(l, r, c);
    }

    sort(lamp, lamp + N);

    cout << dfs(0, 0) << endl;
}

