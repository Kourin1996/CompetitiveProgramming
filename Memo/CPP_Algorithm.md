# Algorithmまとめ

## 基本事項

``#include<algorighm>``でインクルード  
主にSTLのイテレータを引数と取る事で探索などが可能

引数の名前
* begin : 開始イテレータ(開始要素の参照）
* end : 終了イテレータ(終了要素の次の参照）
* value : 値
* f : 関数オブジェクト

## 探索

#### find(begin, end, value)
最初に指定した値と一致した要素のイテレータを返す

#### find_if(begin, end, f)
条件に一致する最初の要素のイテレータを返す

#### adjacent_find(begin, end)
#### adjacent_find(begin, end, f)
同じ値が連続している箇所を探して、最初の要素のイテレータを返す
第3引数がある場合はfを比較関数とする

#### find_first_of(begin1, end1, begin2, end2)
#### find_first_of(begin1, end1, begin2, end2, f)
[begin1,end1)間に[begin2,end2)のいずれかの要素があるか調べる
ある場合は最初に見つかった要素のイテレータを返す
第5引数がある場合はfを比較関数とする

#### find_end(begin1, end1, begin2, end2)
#### find_end(begin1, end1, begin2, end2, f)
[begin1,end1)中に[begin2,end2)の並びがある場合、最後の部分列の先頭イテレータを返す
ない場合はend2を返す

#### count(begin, end, value)
指定した値と一致する要素の数を返す

#### count_if(begin, end, f)
条件に一致する要素の数を数える

#### search(begin1, end1, begin2, end2)
#### search(begin1, end1, begin2, end2, f)
[begin1,end1)中に[begin2,end2)の並びがある場合、最初の部分列の先頭イテレータを返す
見つからない場合はend1を返す

#### search_n(begin, end, n, value)
#### search_n(begin, end, n, value, f)
[begin,end)中にvalueがn個連続する部分列の先頭要素のイテレータを返す

## 二分探索
二分探索の場合は事前にソートが必須

#### lower_bound(begin, end, value)
指定した値以上の要素の先頭イテレータを返す

#### upper_bound(begin, end, value)
指定した値より大きい要素の先頭イテレータを返す

#### equal_range(begin, end, value)
指定した値と一致する範囲の先頭イテレータを返す

#### binary_search(begin. end, value)
指定した値があれば **true** を返す

## ソート

#### sort(begin, end)
#### sort(begin, end, f)
ソートをする

#### stable_sort(begin, end)
#### stable_sort(begin, end, f)
安定ソート（同じ値の場合は並び順が保証されている

## 最大・最初

#### min(val1, val2)
#### min(val1, val2, f)
val1とval2の小さい方を探す

#### max(val1, val2)
#### max(val1, val2, f)
val1とval2の大きい方を探す

#### min_element(begin, end)
#### min_element(begin, end, f)
コンテナの中で最小要素のイテレータを返す

#### max_element(begin, end)
#### max_element(begin, end, f)
コンテナの中で最大要素のイテレータを返す

## 順列
順列の全部の組み合わせを使うには事前のソートが必須

#### next_permutation(begin, end)
#### next_permutation(begin, end, f)
辞書順で次の順番に並びかえる
最初のパターンに達した場合はfalseを返す

#### prev_permutation(begin, end)
#### prev_permutation(begin, end, f)
辞書順で前の順番に並びかえる
辞書順で最後のパターンに達した場合はfalseを返す





