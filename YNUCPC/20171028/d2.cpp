#include<bits/stdc++.h>
using namespace std;
using Int = long long;
using Pi = pair<int, int>;
using vint = vector<Int>;
Int n;
vector<Pi> g;
Int ans;
vint ans_v;
vint used;
vector<vint> divi(44);
void divisor() {
  for(Int i = 2; i < 44; i++) {
    for(Int j = 2; j <= i; j++) {
      if(i%j) continue;
      divi[i].push_back(j);
    }
  }
}
void dfs(Int idx, Int sum, Int prev, vint& vec) {
  if(idx == n) {
    if(ans > sum) {
      ans = sum;
      ans_v = vec;
    }
    return;
  }
  if(sum >= ans) return;
  if(g[idx].first == 1) {
    vec.push_back(1);
    dfs(idx+1, sum, 1, vec);
    vec.pop_back();
    return;
  }
  for(Int i = 1; i <= min(40ll, prev); i++) {
    if(used[i]) continue;
    bool flag = true;
    if(i != 1) {
      for(auto&& v : divi[i]) {
    if(used[v]) flag = false;
    used[v]++;
      }
    }
    if(flag) {
      vec.push_back(i);
      dfs(idx+1, sum+llabs(i-g[idx].first), i, vec);
      vec.pop_back();
    }
    if(i != 1) {
      for(auto&& v : divi[i]) used[v]--;
    }
  }
}
 
signed main(){
  Int cnt = 0;
  divisor();
  while(cin >> n, n) {
    g.clear();
    g.resize(n);
    for(Int i = 0; i < n; i++) {
      cin >> g[i].first;
      g[i].second = i;
    }
    sort(g.begin(), g.end());
    reverse(g.begin(), g.end());
    ans = LLONG_MAX;
    ans_v.clear();
    used.clear();
    used.resize(44, 0);
    vint vec;
    dfs(0, 0, 1000000007, vec);    
    cout << "Case #" << ++cnt << ":";
    vector<Pi> out;
    for(int i = 0; i < n; i++) out.emplace_back(g[i].second, ans_v[i]);
    sort(out.begin(), out.end());
    for(int i = 0; i < n; i++) cout << " " << out[i].second;
    cout << endl;
  }
  return 0;
}