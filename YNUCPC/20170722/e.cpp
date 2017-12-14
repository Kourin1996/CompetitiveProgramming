#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

long T;
std::vector<long> N;
std::vector< std::vector<long> > val;
std::map<long,long> mp;
std::vector<long> p;
long mx;

int main(void){

    long i,j,k,x,c;
    bool f;

    //input
    std::cin >> T;
    N.resize(T);
    val.resize(T);
    for( i=0; i<T; ++i ){
        std::cin >> x;
        N[i] = x;

        val[i].resize(x);
        for( j=0;j<x;++j ){
            std::cin >> val[i][j];
        }
    }

    //solve
    for( i=0; i<T; ++i ){
        mx = -1;
        mp.clear();
        for( j=0; j<N[i]; ++j ){
            mp[ val[i][j] ] += 1;
            mx = std::max(mx, val[i][j] );
        }

        f = true;
        if( mx > 0 ){
            p.resize(mx+1, 0);
            for( j=0; j<mx; ++j ){
                if(mp[j] == 0){
                    f = false;
                    break;
                }

                if( mp[j] <= mp[j+1] ){
                    c = mp[j];
                    mp[j+1] -= c;
                    mp[j] = 0;

                    p[j] = c;
                }else{
                    f = false;
                    break;
                }
            }
            f = f && (mp[mx] == 0);
        }else{
            f = false;
        }

        std::cout << "Case " << i+1 << ": ";
        if( f ){
            for( j=0; j<mx; ++j ){
                std::cout << "(";
            }
            for( j=mx-1; j>=0; --j ){
                std::cout << ")";
                for( k=1; k<p[j]; ++k ){
                    std::cout << "()";
                }
            }
        }else{
            std::cout << "invalid";
        }
        std::cout << std::endl;
    }

    return 0;
}
