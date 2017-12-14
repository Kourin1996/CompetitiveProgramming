# STLのまとめ

## STL一覧
* [array](#array_bitset)
* [bitset](#array_bitset)
* [vector](#vector)
* [list](#list)
* [forward_list](#list)
* stack
* queue
* [deque](#deque)
* [priority_queue](#priority_queue)
* [set](#set)
* [multiset](#multi_set)
* [unordered_set](#unorder_set)
* [unordered_multiset](#unorder_set)
* [map](#map)
* [multimap](#map)
* [unordered_map](#map)
* [unordered_multimap](#map)


## 共通インターフェース
各々のSTLに共通に実装されているメソッド

* at(size_t) : 要素アクセス(範囲外の場合は例外送出)
* [] : 要素アクセス(範囲外チェック無し)
* front() : 先頭要素にアクセス
* back() : 末尾要素にアクセス
* data : 生のコンテナ取り出し(一部)

* begin() : 先頭要素のイテレータ（参照）の取得
* end() : 末尾の次の要素のイテレータ（参照）の取得
* rbegin() : 末尾の要素の逆イテレータ（参照）の取得
* rehd() : 先頭要素の前の逆イテレータ（参照）の取得

* empty() : コンテナが空か取得
* size() : 要素数を取得
* clear() : 全要素を消す

* fill(begin,end,value) : コンテナを指定された値で埋める
* fill_n(begin,size,value) : コンテナを指定された値で埋める
* push_back(value) : 末尾に追加
* pop_back(value) : 先頭に要素を追加

(list, dequeなど）
* pop_back() : 末尾要素消去
* pop_front() : 先頭要素消去

## <a name ="array_bitset">array, bitset(固定配列、固定ビット列)

bitsetはビット演算やシフト演算も可能  
bitsetの0番はLSBのことなので注意

```cpp
#include <array>
std::array<int,3> ary = {3,1,4};

#include <bitset>
std::bitset<16> bits(4);
```

### bitset専用のメソッド
* count : 1になってるビットの数
* test : 任意の位置が1かどうか返す
* all : 全てのビットが1かどうか返す
* any : いずれかのビットが1かどうか返す
* none : 全てのビットが0かどうか返す
* to_ulong : unsigned longに変換する
* to_ullong : unsigned long long に変換する
* to_string : 文字列に
* rehd : 先頭要素の前の逆イテレータ（参照）の取得変換する
* rehd : 先頭要素の前の逆イテレータ（参照）の取得

## <a name ="vector">vector(動的配列)
要素数が可変な配列  
ただし、内部実装は普通の配列なので、最大要素数は事前に分かってる方が好ましい

### vector専用のメソッド

* resize : 要素数を変更する
* reserve * capacity（内部配列の大きさ）を変更する

## <a name ="list">list, forward_list
要素挿入・消去は速い  
しかし、ランダムアクセスは遅い  
foward_listは単方向リストなので効率が良いが、size(), insert(), erase()などがない

### list専用のメソッド

* sort() : コンテナをソートする
* unique() : コンテナ内の重複要素を消去（ソート済である事)
* insert(it, elem) : 要素を挿入(1番目の引数はイテレータ)
* erase(from, to) : 指定範囲を消去(引数はイテレータ)
* remove(elem) : コンテナから一致する値の要素を消す
* remove_if(lambda) : コンテナから条件に合う要素を消す(ラムダ関数を渡す)

## <a name ="deque">deque

先頭・末尾への要素の追加・消去が高速  
stackとqueueはdequeを用いて実装可能

## <a name ="priority_queue">priority_queue

内部コンテナの要素が自動でソートされている  
要素をランダムに追加していき、常に大きいものから取り出したい時とかに使う  

### 比較関数の渡し方

デフォルトでは大きい順になっている  
プリミティブな値の場合はlessやgreaterを使う事で順番を変えられる  

```cpp
//大きい順
std::priority_queue< int, std::vector<int>, std::less<int> > q;

//小さい順
std::priority_queue< int, std::vector<int>, std::greater<int> > q;

//ラムダ関数を使う場合(leftが優先度低い場合にtrueを返すような関数を定義)
auto c = [](int l, int r) { if (l % 2 == 0) return r % 2 != 0 || l >= r; else return r % 2 != 0 && l < r; };
std::priority_queue<int, std::vector<int>, decltype(c)> q(c);
```

## <a name ="set">set

値がユニークなデータのコンテナ

### set専用のメソッド

* find : 指定したキーの要素のイテレータを返す（ない場合はendと同じ場所を返す)
* lower_bound : 指定した値以上の最初の要素のイテレータを返す
* upper_bount : 指定した値より大きい最初の要素のイテレータを返す

## <a name ="multi_set">multi_set

重複を許すset  
findは合致する要素の最初のイテレータを返す
countは合致する要素の数を返す

### multi_set専用のメソッド
* find : 指定したキーの要素のイテレータを返す（ない場合はendと同じ場所を返す)
* equal_range : 指定した要素と等しい範囲を返す（イテレータのペア、どのキーともマッチしなかった場合は差分が0になる)
* lower_bound : 指定した値以上の最初の要素のイテレータを返す
* upper_bount : 指定した値より大きい最初の要素のイテレータを返す

## <a name ="unorder_set">unordered_set, unordered_multiset
ソートされていないset, multi_set  

## <a name ="map">map, multimap, unordered_map, unordered_multimap

連想配列（特定の型をキーとして要素にアクセスできる)  
equal_range, lower_bound_upper_boundはキーを元に探索する  

orderedなmapはO(log n)で要素アクセスが可能  
unorderedなmapは最悪O(n)必要




