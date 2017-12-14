# C++の雑記

## 入出力

### cin, coutの高速化

注.printf, scanfとの同期が取れなくなる
```cpp
std::ios_base::sync_with_stdio(false);
std::cin.tie(0);
```

### 小数表示(桁指定)
```cpp
#include <iomanip>
std::cout << std::fixed << std::setprecision(2) << 3.141; //"3.14"
```

### 小数表示(最大桁)
```cpp
#include <iomanip>
std::cout << std::fixed << set::setprecision(std::numeric_limits<double>::max_digits10) << 3.14159;
```

### printf, scanfのフォーマット指定子

| 指定子 | 型                                    | 説明                   |
|:------:|---------------------------------------|------------------------|
|   %c   | char                                  | 文字                   |
|   %s   | char*                                 | 文字列                 |
|   %d   | int, short                            | 10進整数               |
|   %u   | unsigned int,unsigned short           | 符号無し10進整数       |
|   %o   | int,short,unsigned int,unsigned short | 8進整数                |
|   %x   | int,short,unsigned int,unsigned short | 16進整数               |
|   %f   | float                                 | 実数                   |
|   %e   | float                                 | 指数形式実数           |
|   %ld  | long                                  | 倍精度10進整数         |
|   %lu  | unsigned long                         | 符号無し倍精度10進整数 |
|   %lo  | long,unsigned long                    | 倍精度8進整数          |
|   %lx  | long, unsigned long                   | 倍精度16進整数         |
|   %lf  | double                                | 倍精度実数             |

## 計算

### 数値型の範囲

| 型名           | ビット幅 |         下限         |         上限         | 入るオーダー |
|----------------|:--------:|:--------------------:|:--------------------:|:------------:|
| char           |     8    |                 -128 |                  127 | 10^1         |
| unsigned char  |     8    |                    0 |                  255 | 10^1         |
| short          |    16    |               -32768 |                32767 | 10^3         |
| unsigned short |    16    |                    0 |                65535 | 10^3         |
| int            |    32    |          -2147483648 |           2147483647 | 10^9         |
| unsigned int   |    32    |                    0 |           4294967295 | 10^9         |
| long           |    64    | -9223372036854775808 |  9223372036854775807 | 10^18        |
| unsigned long  |    64    |                    0 | 18446744073709551615 | 10^18        |
| float          |    32    |          1.17549e-38 |          3.40282e+38 | 10^38        |
| double         |    64    |         2.22507e-308 |         1.79769e+308 | 10^308       |
| long double    |    128   |         3.3621e-4932 |        1.18973e+4932 | 10^4932      |

### 最大値・最小値の取得

```cpp
#include<limits>
std::numeric_limits<char>::min();
std::numeric_limits<char>::max();

#include <climits>
CHAR_MIN ...etc
```

#### ビット数の取得

```cpp
std::numeric_limits<char>::digits;
```

### 切り上げ
```cpp
(a + (b-1))/b;

float ceilf(float);
double ceil(double);
long double ceill(long double);
```

### 四捨五入
```cpp
(a + (b/2))/b;
```

|     返値    |  関数名  |     引数    |
|:-----------:|:--------:|:-----------:|
|    double   |   round  |    double   |
|    float    |  roundf  |    float    |
| long double |  roundl  | long double |
|     long    |  lround  |    double   |
|     long    |  lroundf |    float    |
|     long    |  lroundl | long double |
|  long long  |  llround |    double   |
|  long long  | llroundf |    float    |
|  long long  | llroundl | long double |

### mod(足し算、引き算)
結果にMODを取る
```cpp
const int MOD = 1e9 + 7;
int add(int a, int b) {
  return (a+b) $ MOD;
}
```

### mod（掛け算)
余り同士を掛けた後に、再度余りを取る
```cpp
const int MOD = 1e9 + 7;
int mul(int a, int b) {
  return ((a%MOD) * (b%MOD)) % MOD;
}
```

### mod(割り算)
フェルマーの小定理を使う
```cpp
const int MOD = 1e9 + 7;
int mul(int a, int b) {
  return ((a%MOD) * (b%MOD) % MOD;
}

int power(int a, int b) {
  if( y == 0   ) return 1;
  if( y == 1   ) return x % MOD;
  if( y%2 == 0 ) return power(x,y/2) * power(x,y/2) % MOD;
                 return power(x,y/2) * power(x,y/2) * x % MOD;
}

int div(int a, int b) {
  return mul(a, power(b,mod-2));
}
```

### その他

- 前置インクリメントの方が速い(i++)
- forループの継続条件はループ毎に評価するので, 末尾イテレータは事前に評価しておく
```cpp
for(vector<int>::iterator it=v.begin(), v_end = v.end(); it != v_end; ++it)
```
- lambda式を用いたソート
```cpp
#include <algorithm>
sort(_begin,_end,[](type x, type y)->int{return x < y}) //smaller
```
