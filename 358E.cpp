#include <bits/stdc++.h>
#include <atcoder/all>
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
#define all(x) (x).begin(), (x).end()

void yesno(bool flag){cout << (flag ? "Yes" : "No") << endl;}

using mint = atcoder::modint998244353;

mint ans;
vll kaijyo;

void calc(vll &c, ll &k){
    ans += kaijyo[k];
    rep(26) ans /= kaijyo[c[i]];
}

void vec(ll i, vll &c, vll &cm, ll sum, ll k){
    if(i == 26) {calc(c, k); return;}
    rep(i, cm[i]+1){
        c[i] = i;
        sum += i;
        if(sum == k){
            vec(26, c, cm, sum, k);
            return;
        }
        vec(i+1, c, cm, sum, k);
    }
}

int main() {
    ll k; cin >> k;
    vll cm(26);
    rep(26) cin >> cm[i];
    vll c(26);
    kaijyo.emplace_back(1);
    ans = 0;
    rep(i, 1, 1001) kaijyo.emplace_back(kaijyo[i-1]*i);
    vec(0, c, cm, 0, k);
    cout << ans.val() << endl;
}