#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;

int n;
string s[20];

int find(int x,vector<int> &par) {
    if( x == par[x] ) return x;
    return par[x] = find(par[x],par);
}

void unite(int x,int y,vector<int> &par) {
    x = find(x,par), y = find(y,par);
    if( x != y ) par[x] = y;
}

void normalize(vector<int> &par) {
    map<int,int> mp;
    int ID = 0;
    rep(i,(int)par.size()) {
        if( mp.count(par[i]) ) continue;
        mp[par[i]] = ID++;
    }
    rep(i,(int)par.size()) par[i] = mp[par[i]];
}


bool debug = false;
const ll mod = 10000;
void compute() {
    vector<ll> coef(n*n+1);
    coef[0] = 1;
    REP(i,1,n*n+1) {
        coef[i] = coef[i-1] * (ll)i;
        coef[i] %= mod;
    }

    map<vector<int>,ll> dp[2];
    {
        vector<int> init;
        rep(i,n) init.push_back(i);
        dp[0][init] = 1; 
    }
    int cur = 0;
    rep(i,n) {
        rep(j,i) {
            if( s[i][j] == 'N' ) continue;
            if( debug ) cout << "(" << j << "," << i << ")" << endl;
            int nex = ( cur + 1 ) % 2;
            dp[nex].clear();
            for(auto v : dp[cur]) {
                int s = j, t = i;
                vector<int> par = v.first; 
                ( dp[nex][par] += v.second ) %= mod;
                //rep(k,(int)par.size()) cout << par[k] << " "; cout << endl;
                unite(s,t,par);
                //rep(k,(int)par.size()) cout << par[k] << " "; cout << endl;
                //if( par == v.first ) continue;
                normalize(par);
                //rep(k,(int)par.size()) cout << par[k] << " "; cout << endl;
                //cout << "second = " << v.second << endl;
                //puts("");
                //if( par == v.first ) continue;
                ( dp[nex][par] += v.second ) %= mod;
                //cout << "? " << dp[nex][par] << endl;
            }
            cur = nex;
        }
    }
    ll answer = 0;
    for(auto v : dp[cur]) {
        vector<int> par = v.first;
        bool ok = true;
        {
            set<int> S;
            rep(i,(int)par.size()) S.insert(par[i]);
            if( S.size() != 1 ) ok = false;
        }
        if( ok ) {
            ll value = v.second;
            answer += value;
            answer %= mod;
        }
    }
    cout << answer << endl;
}

int main() {
    int CNT = 1;
    int T;
    while( cin >> T ) {
        while( T-- ) {
            cin >> n;
            cout << "Case " << CNT++ << ": ";
            rep(i,n) cin >> s[i];
            compute();
        }
    }
    return 0;
}