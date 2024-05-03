#include <bits/stdc++.h>
#include <ranges>
using namespace std;
using ll = long long;
using str = string;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
template<class T>using vc = vector<T>;
template<class T>using vvc = vc<vc<T>>;
using vint = vc<int>;
using vll = vc<ll>;
using vstr = vc<str>;
using vpint = vc<pint>;
using vpll = vc<pll>;
using vbool = vc<bool>;
using vvint = vvc<int>;
using vvll = vvc<ll>;

#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n)          for(ll i = 0; i < (n); ++i)
#define rep2(i, n)       for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b)    for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define each1(a)       for(auto&& i : a)
#define each2(i,a)     for(auto&& i : a)
#define each3(x,y,a)   for(auto&& [x, y] : a)
#define each4(x,y,z,a) for(auto&& [x, y, z] : a)
#define each(...) overload4(__VA_ARGS__, each4, each3, each2, each1)(__VA_ARGS__)

void yesno(bool flag){cout << (flag ? "Yes" : "No") << endl;}

int main() {
    int N, M;
    cin >> N >> M;
    vector<long> L(N);
    for (int i = 0; i < N; ++i) {
        cin >> L[i];
        ++L[i]; // 先頭に空白をつけておく
    }
    long lower = ranges::max(L) - 1; // 答えは max L[i] 以上
    long upper = reduce(begin(L), end(L)); // 答えは ∑ L[i] 以下
    // 二分探索
    while (lower + 1 < upper) {
        long middle = (lower + upper) / 2;
        int rows = 1; // 今の行数
        long length = 0; // 先頭から何文字目か
        for (int i = 0; i < N; ++i) {
            length += L[i]; // 行の末尾に追加してみる
            if (length > middle) { // はみ出たら
                ++rows; // 改行して
                length = L[i]; // 先頭に追加
            }
        }
        if (rows > M) // 縦幅が足りていなければ
            lower = middle; // 答えは middle より大きい
        else // 足りていれば
            upper = middle; // 答えは middle 以下
    }
    // 答えから 1 を引いて出力
    cout << upper - 1 << endl;
    return 0;
}