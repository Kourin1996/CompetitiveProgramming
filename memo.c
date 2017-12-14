//cin,cout高速化(scanf,printfとの同期が取れなくなる)
std::ios_base::sync_with_stdio(false);
std::cin.tie(0);

//前置インクリメント(++i)の方が早い

//継続条件判定の高速化(初期化子でend()のポインタを記憶しておく)
for(vector<int>::iterator it=v.begin(), v_end = v.end(); it != v_end; ++it)

//lambda式を用いたsort
#include <algorithm>
sort(_begin,_end,[](type x, type y)->int{return x < y}) //smaller

//小数表示
#include <iomanip>
std::cout << std::fixed << std::setprecision(2) << 3.141; //"3.14"
//小数表示(最大桁)
#include <iomanip>
std::cout << std::fixed << set::setprecision(std::numeric_limits<double>::max_digits10) << 3.14159;

//小数切り捨て
#include <cmath>
double floor(double x)

//小数切り上げ
#include <cmath>
double ceil(double x)

//順列
#include <algorithm>
std::vector<int> v = {1,2,3,4};
std::sort(vec.begin(), vec.end());
do{
    for(auto x : v){
        std::cout << x;
    }
    std::cout << std::endl;
}while( next_permutation(v.begin(), v.end()) )

//橋か判定する方法
//各点についてpre,lowという2つのデータをもつ
//preはdfsの深さ
//lowはその点から行ける頂点のpreの最小値を持つ
//橋になる場合、pre==lowとなるはずである
//つまり、pre==lowである頂点-1が橋である
int dfs(int i, int d, int p) {
    if(data[i].fst != -1) {
        return data[i].snd;
    }
    data[i].fst = d;
    data[i].snd = d;
    EACH(it, g[i]) {
        if(*it == p) continue;
        int res = dfs(*it, d+1, i);
        data[i].snd = std::min(data[i].snd, res);
    }
    return data[i].snd;
}