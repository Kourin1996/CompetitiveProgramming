#include <iostream>
#include <algorithm>

int n;
long m, p[1001], q[1100000];

int main(){
	while(std::cin >> n >> m){
        if(n == 0 && m == 0){
            break;
        }

		p[0]=0;
		for(int i=1; i<=n; ++i){
            std::cin >> p[i];
        }
        std::sort(p, p+n);

        long k=0;
		for(int i=0; i<=n; ++i){
            for(int j=i; j<=n; ++j){
		        q[k++]=p[i]+p[j];
            }
        }
        std::sort(q, q+k);

        long ans=0;
		for(long i=0; i<k; ++i){
			long rem=m-q[i];
			if(rem<0) break;

            long l=0, r=k;
			while(l<r){
				long c=(l+r)/2;
				if(rem>q[c]){
					l=c+1;
				}
				else if(rem<q[c]){
					r=c;
				}
				else{
                    break;
                }
			}
			ans=std::max(ans, q[i]+q[r-1]);
		}
	    std::cout << ans << std::endl;
    }
}
