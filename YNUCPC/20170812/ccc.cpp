#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

const int N = 20005;
int a[N];
long long sum[N];
bool cmp(int a,int b)
{
    return a > b;
}

int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        std::cin >> n;
        for(int i = 1;i <= n;i++){
            std::cin >> a[i];
        }

        sort(a+1,a+1+n,cmp);

        for(int i = 1;i <= n;i++){
            sum[i] = sum[i-1] + a[i];
        }
        int p = n/3, q;
        long long minn = LLONG_MAX;
        for(int i = 1;i <= p;i++){
            q = (n-i)/2;
            for(int j = i+1;j <= i+q;j++){
                minn = min(minn, sum[i]*i + (sum[j]-sum[i])*(j-i) + (sum[n]-sum[j])*(n-j));
            }
        }
        cout << minn << endl;
    }
}
